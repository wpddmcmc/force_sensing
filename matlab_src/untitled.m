ButtonHandle=uicontrol('Style','PushButton','String','Break','Callback','delete(gcbf)');
% while(ishandle(ButtonHandle))
%     %drawnow
%     disp('looping...')
% end

while(1)
    disp('looping...');
    drawnow;
    if ~ishandle(ButtonHandle)
        disp('Loop stopped by user');
        break;
    end
end