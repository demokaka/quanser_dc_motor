% get all acados library files .lib
% recursively
acados_lib_root = 'C:\Users\dinhck\deps\acados\lib';
files_lib = dir(fullfile(acados_lib_root, '*.lib'));

N_libs = numel(files_lib);
lines_libs = cell(N,1);
out_lines = '';
for i = 1:N_libs
    fullpath = fullfile(files_lib(i).folder, files_lib(i).name);
    % create string of format: "path\file.c"
    lines_libs{i} = ['"', fullpath, '"'];
    out_lines = [out_lines, lines_libs{i}, sprintf('\n')];
end


% Print out all the .lib libraries files
disp(out_lines);

% get all c_generated_code source files .c
% recursively
root_generated_code = fullfile(pwd, 'c_generated_code');
files = dir(fullfile(root_generated_code, '**', '*.c'));

N = numel(files);
lines = cell(N,1);

for i = 1:N
    fullpath = fullfile(files(i).folder, files(i).name);
    % create string of format: "path\file.c"
    lines{i} = ['"', fullpath, '"'];
end

% Combine into 1 block text
out = strjoin(lines, newline);

% Print out all the .c source files
disp(out);
