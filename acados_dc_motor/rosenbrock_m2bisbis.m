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

%% Simulink minimal example
% get default simulink_opts
% simulink_opts = get_acados_simulink_opts;

%% Compile Sfunctions
cd c_generated_code

make_sfun; % ocp solver
% make_sfun_sim; % integrator