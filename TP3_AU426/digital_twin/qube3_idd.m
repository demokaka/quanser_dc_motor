% identification vs physic-based modeling

%% Physic-based transfer functions
G = tf(motor_ss);         % transfer function matrix
G2 = G(2);                 
[z,p,k] = zpkdata(G,'v');

[num2, den2] = tfdata(G2,'v');
K2 = num2(end);
tau2 = den2(1)/den2(end);

fprintf("Gain (phys) K2 = %.4f (rad/s)/V\n", K2);
fprintf("Time constant tau2 = %.4f s\n", tau2);

%%
step = 10;
Ts = speed(step+1,1)-speed(1,1);
u_data = voltage(1:step:end,2);
y_data = speed(1:step:end,2);
data = iddata(y_data, u_data, Ts);
data.TimeUnit = 's';
data.InputName = "Voltage";
data.InputUnit = "V";
data.OutputName = "Speed";
data.OutputUnit = "rad/s";

%% estimate transfer function using MATLAB functions
np = 1; nz = 0;    % 1 pole, 0 zero
sys1 = tfest(data, np, nz);
G1 = tf(sys1);
[z1,p1,k1] = zpkdata(sys1,'v');

[num1, den1] = tfdata(sys1,'v');
K1 = num1(end);
tau1 = den1(1)/den1(end);

fprintf("Gain (ident) K1 = %.4f (rad/s)/V\n", K1);
fprintf("Time constant tau1 = %.4f s\n", tau1);

A1 = [0 1; 0 -1/tau1];
B1 = [0; K1];
C1 = C;
D1 = D;



