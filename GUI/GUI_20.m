function [] = GUI_20()
% Demonstrate how to get the chosen string from a popup.  
% Creates a popup and an editbox.  When the user selects a choice from the 
% popup, this choice will appear in the editbox.
%
%
% Author:  Matt Fig
% Date:  7/15/2009

S.fh = figure('units','pixels',...
              'position',[300 300 300 110],...
              'menubar','none',...
              'name','GUI_20',...
              'numbertitle','off',...
              'resize','off');
S.pp = uicontrol('style','pop',...
                  'units','pixels',...
                  'position',[20 10 260 40],...
                  'string',{'one','two','three','four'});
S.ed = uicontrol('style','edit',...
                 'units','pix',...
                 'position',[20 60 260 30],...
                 'fontsize',16,'string','one');

set(S.pp,'callback',{@pp_call,S});  % Set the callback.


function [] = pp_call(varargin)
% Callback for the popup.
S = varargin{3};  % Get the structure.
P = get(S.pp,{'string','val'});  % Get the user's choice.
set(S.ed,'string',P{1}{P{2}});  % Assign the user's choice to the edit.