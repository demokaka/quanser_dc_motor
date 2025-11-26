% initial run for acados
% initial_run.m
%%
clear; clc; close all;
%%

% --- acados root (repo) ---
acados_root = 'C:\Users\dinhck\deps\acados';

setenv('ACADOS_INSTALL_DIR', fullfile(acados_root));
setenv('ENV_RUN','true');  % used by some helper scripts

% Add MATLAB interface to path
addpath(fullfile(acados_root,'interfaces','acados_matlab_octave'));
addpath(fullfile(acados_root,'external','jsonlab'));

% Make sure MATLAB uses MSVC
mex -setup C; mex -setup C++;