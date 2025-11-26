%%
clear; clc; close all;

% Load parameters
qube3_param;

% State-space matrices
A = [0 1; 0 -(km*kt)/(Rm*Jeq)];
B = [0; kt/(Rm*Jeq)];
C = eye(2);
D = zeros(2,1);

%simulate a step to the state space model
motor_ss=ss(A,B,C,D);
step(motor_ss,5);