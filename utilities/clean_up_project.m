function clean_up_project()
%clean_up_project   Clean up project
% 
%   Clean up the environment for the current project. This function undoes
%   the settings applied in "set_up_project". It is set to Run at Shutdown.

%   Copyright 2015 The MathWorks, Inc.

% Reset the location where generated code and other temporary files are
% created (slprj) to the default:
Simulink.fileGenControl('reset');

% Use Simulink Project API to get the current project:
project = simulinkproject;

% Set the location of slprj to be the "work" folder of the current project:
projectRoot = project.RootFolder;



end
