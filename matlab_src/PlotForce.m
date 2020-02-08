zerotime = arTimeStamp(1);

datalength=length(Force_res(:,7));
for k = 1:datalength
    NormTime(k) = arTimeStamp(k) - zerotime;
end

figure(1)
maxForce = max(max(Force_res));

for k = 1:7
    subplot(2,4,k)

    plot(NormTime,Force_res(:,k))
    title(['Sensor ' num2str(k)])
    xlabel('Time / s')
    ylabel('Force / N')
    ylim([-0.4 maxForce+1])
    grid on
end