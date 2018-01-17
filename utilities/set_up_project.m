function set_up_project()
%set_up_project  Configure the project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

%   Copyright 2011-2014 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
project = simulinkproject;

% Set the location of slprj to be the "work" folder of the current project:
projectRoot = project.RootFolder;

Simulink.architecture.register(fullfile(projectRoot,'include','CustomArchitecture.xml'));

end
