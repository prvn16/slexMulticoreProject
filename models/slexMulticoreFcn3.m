classdef slexMulticoreFcn3 < matlab.System & matlab.system.mixin.CustomIcon 
% Algorithm Design
% Copyright 2015 The MathWorks, Inc.
%#codegen
    properties
        nIter = 1;
    end

    methods 
        function this = slexComponent(varargin)
            setProperties(this, nargin, varargin{:});
        end
    end

    methods(Access=protected)
        function icon = getIconImpl(~)
            icon = sprintf('Fcn3');
        end
        
        function Multiplier=stepImpl(this,u1,u2)
            expensiveComputation(this);
            Multiplier = u1*u2;
        end
        
        function expensiveComputation(this)
            y = 1;
            for i=1:this.nIter
                y = y - sin(y)/cos(y);
            end
        end
    end
end
