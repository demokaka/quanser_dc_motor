%%
clear; clc; close all;
%%

solver_dir = fullfile(pwd, 'c_generated_code');
% json_file  = fullfile(solver_dir, 'acados_ocp_generic_nlp.json');
json_file  = fullfile(pwd, 'acados_ocp_nlp.json');

solver_creation_opts = struct( ...
    'json_file', 'acados_ocp_nlp.json', ...
    'build', true, ...              % không build lại
    'generate', false, ...           % không render template lại
    'compile_mex_wrapper', false, ...% không compile mex lại
    'compile_interface', false, ...
    'output_dir', solver_dir);

% tạo solver từ json + code đã build sẵn
ocp_solver = AcadosOcpSolver([], solver_creation_opts);

%% solve the NLP
% initial guess
init_x = [2.5; 3.0];
ocp_solver.set('init_x', init_x);

% set the parameters
p_value = [1];
ocp_solver.set('p', p_value);

% solve and time
tic
ocp_solver.solve();
time_external = toc;
% internal timing
total_time = ocp_solver.get('time_tot');

% check status
status = ocp_solver.get('status');
if status ~= 0
    warning(['solver failed with status ',num2str(status)]);
end

% display results
x_opt = ocp_solver.get('x', 0);
disp('Optimal solution:')  % should be [1;1] for p = [1;1]
disp(x_opt)
disp(['Total time (internal): ', num2str(1e3*total_time), ' ms'])
disp(['Total time (external): ', num2str(1e3*time_external), ' ms'])

%
solving_time = [];
solving_internal_time = [];
xy_sol = [];
timer = tic;
for r_value=linspace(1,3,25)
    % set the parameters
    p_value = r_value;
    ocp_solver.set('p', p_value);
    timer_sol = tic;
    ocp_solver.solve();
    sol_t = toc(timer_sol);
    solving_time = [solving_time, sol_t*1e3];
    % internal timing
    total_internal_time = ocp_solver.get('time_tot');
    solving_internal_time = [solving_internal_time, total_internal_time*1e3]
    xy_sol = [xy_sol, ocp_solver.get('x', 0);]

end
total_time = toc(timer);  