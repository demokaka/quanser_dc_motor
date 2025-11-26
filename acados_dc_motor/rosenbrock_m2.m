%% clear everything
clc
clear all
close all

check_acados_requirements()
import casadi.*
%%
% try to use acados to create a general optimization solver

simulink_opts = get_acados_simulink_opts;
% inputs
% simulink_opts.inputs.x_init = 1;
simulink_opts.inputs.reset_solver = 1;
simulink_opts.inputs.lh_e = 0;
simulink_opts.inputs.uh_e = 0;
% outputs
% simulink_opts.outputs.utraj = 1;
simulink_opts.outputs.xtraj = 1;
simulink_opts.outputs.cost_value = 1;

% options needed for the Simulink example
if ~exist('simulink_opts','var')
    % disp('using acados simulink default options')
    % simulink_opts = get_acados_simulink_opts;
    disp('using empty simulink_opts to generate solver without simulink block')
    simulink_opts = [];
end

%% generic NLP formulation
% min. f(x,p)
% s.t. glb <= g(x,p) <= gub

x = casadi.SX.sym('x',2);
p = casadi.SX.sym('p',1);
f =  (1-x(1))^2 + (x(2)-x(1)^2)^2;
g = x(1)^2 + x(2)^2 - p;
glb = 0;
gub = 0;
%% write a model

model = AcadosModel();
model.name = 'generic_nlp';
model.x = x;
model.p = p;

%% acados ocp formulation
ocp = AcadosOcp();
ocp.name = 'nlp_solver';
ocp.model = model;

% (terminal) cost
ocp.cost.cost_type_e = 'EXTERNAL';
ocp.model.cost_expr_ext_cost_e = f;

% (terminal) constraints
ocp.model.con_h_expr_e = g;
ocp.constraints.lh_e = -get_acados_infty();
ocp.constraints.uh_e = gub;

% initial parameter values
ocp.parameter_values = zeros(length(model.p),1);

%% solver options
ocp.solver_options.N_horizon = 0;
ocp.solver_options.nlp_solver_type = 'SQP';
ocp.solver_options.qp_solver = 'PARTIAL_CONDENSING_HPIPM';

ocp.simulink_opts = simulink_opts;

%% create the solver
ocp_solver = AcadosOcpSolver(ocp);

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