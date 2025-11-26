% - Qube servo - DC motor control


%%
clc; clear; close all;


%%
% Load parameters
qube3_param;

% Continuous system
A_cont = [0 1; 0 -(km*kt)/(Rm*Jeq)];
B_cont = [0; kt/(Rm*Jeq)];
C_cont = eye(2);
D_cont = zeros(2,1);

% System dimensions
[dx, du] = size(B_cont);
dy = size(C_cont, 1);

Ts = 0.02; % Sampling time
sys_cont = ss(A_cont, B_cont, C_cont, D_cont); % Create continuous state-space system
sys_disc = c2d(sys_cont, Ts, 'zoh'); % Discretize the system using zero-order hold

[A, B, C, D] = ssdata(sys_disc);
% Initial conditions
x0 = [0; 0];
u0 = zeros(du, 1);

theta_max = 1;
omega_max = 5/km;
v_max = 5;
% Weighting matrices
Q = diag([1/theta_max^2,1/omega_max^2]);
R = 1/v_max^2;

K_lqr = lqr(A_cont, B_cont, Q, R);

%%
Tfinal = 10;
t = 0:Ts:Tfinal;
t = t(1:end-1);
Nsim = length(t);
% Reference (tracking only theta)
ref1 = -(pi/4) * square(2*pi*0.5*t);
ref2 = zeros(size(t));
ref = [ref1; ref2];

%% Simulation loop
xsim = zeros(dx, Nsim+1);
xsim(:,1) = x0;
usim = zeros(du, Nsim);
ysim = zeros(dy, Nsim);
usiminit = u0;

timer = tic;
for i = 1:Nsim
    xref_val = ref(:,i);

    u_lqr = K_lqr*(xref_val - xsim(:,i));
    usim(:,i) = u_lqr;
    xsim(:,i+1) = A*xsim(:,i) + B*usim(:,i);
    ysim(:,i) = C*xsim(:,i) + D*usim(:,i);

end
time_sim = toc(timer);

%% Plotting
figure;
plot(t, ysim(1,:), 'b', 'LineWidth', 1.5); hold on;
plot(t, ref(1,:), 'r--', 'LineWidth', 1.5);
xlabel('Time [s]'); ylabel('\theta [rad]');
legend('Output', 'Reference');
title('Position Tracking');

figure;
plot(t, usim);
xlabel('Time [s]');
ylabel('Control Input u [V]');
title('Control Input');

%% Errors
error = abs(ysim - ref);
AvgError = mean(error, 2);
fprintf('Average error θ: %.4f rad\n', AvgError(1));
fprintf('Average control effort: %.4f V\n', mean(abs(usim)));

%% Time
fprintf("Total simulation time: %f seconds. \n", time_sim);

