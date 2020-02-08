
cam1 = webcam(1);

% initialization

figure(1)
imshow(y_img);
figure(2)
imshow(img);

%%
for i = 1:1:100
img = snapshot(cam1);

y_po_ini1(i) = mean(mean(rgb2gray(img(286:339,768:831,:))));
y_ne_ini1(i) = mean(mean(rgb2gray(img(157:231,962:1052,:))));
x_po_ini1(i) = mean(mean(rgb2gray(img(297:369,900:968,:))));
x_ne_ini1(i) = mean(mean(rgb2gray(img(159:214,805:876,:))));
z_po_ini1(i) = mean(mean(rgb2gray(img(233:272,864:933,:))));


y_po_ini2(i) = mean(mean(rgb2gray(img(561:637,269:358,:)))) ;
y_ne_ini2(i) = mean(mean(rgb2gray(img(450:502,494:553,:))));
x_po_ini2(i) = mean(mean(rgb2gray(img(589:683,440:523,:))));
x_ne_ini2(i) = mean(mean(rgb2gray(img(425:474,353:422,:))));
z_po_ini2(i) = mean(mean(rgb2gray(img(503:563,393:456,:))));

i
end

initial_y_po1 = mean(y_po_ini1);
initial_y_ne1 = mean(y_ne_ini1);
initial_x_po1 = mean(x_po_ini1);
initial_x_ne1 = mean(x_ne_ini1);
initial_z1 = mean(z_po_ini1);


initial_y_po2 = mean(y_po_ini2);
initial_y_ne2 = mean(y_ne_ini2);
initial_x_po2 = mean(x_po_ini2);
initial_x_ne2 = mean(x_ne_ini2);
initial_z2 = mean(z_po_ini2);

pre_z1 = 0;
pre_x_ne1 = 0;
pre_y_ne1 = 0;
pre_x_po1 = 0;
pre_y_po1 = 0;

pre_z2 = 0;
pre_x_ne2 = 0;
pre_y_ne2 = 0;
pre_x_po2 = 0;
pre_y_po2 = 0;

for i = 1:1:2000
    
img = snapshot(cam1);


y_po1 = mean(mean(rgb2gray(img(286:339,768:831,:)))) - initial_y_po1;
y_ne1 = mean(mean(rgb2gray(img(157:231,962:1052,:)))) - initial_y_ne1;
x_po1 = mean(mean(rgb2gray(img(297:369,900:968,:)))) - initial_x_po1;
x_ne1 = mean(mean(rgb2gray(img(159:214,805:876,:)))) - initial_x_ne1;
z_po1 =  -(mean(mean(rgb2gray(img(233:272,864:933,:)))) - initial_z1);



y_po2 = mean(mean(rgb2gray(img(561:637,269:358,:)))) - initial_y_po2;
y_ne2 = mean(mean(rgb2gray(img(450:502,494:553,:)))) - initial_y_ne2;
x_po2 = mean(mean(rgb2gray(img(589:683,440:523,:)))) - initial_x_po2;
x_ne2 = mean(mean(rgb2gray(img(425:474,353:422,:)))) - initial_x_ne2;
z_po2 =  -(mean(mean(rgb2gray(img(503:563,393:456,:)))) - initial_z2);


y_int1 = y_po1-y_ne1;
z_int1 = z_po1;

if (x_ne1<0)
   x_int1 = x_ne1;
else
   x_int1 =  x_po1;
end

y_int2 = y_po2-y_ne2;
x_int2 = x_po2-x_ne2;
z_int2 = z_po2;



%%%% z- axis %%%%  
fz_s1(i) = 0.0027052*z_int1^4 -0.011676*z_int1^3 -0.010948*z_int1^2 + 0.71242*z_int1  -0.004521;
fy_s1(i) = 0.095471*y_int1;% + 0.30823;
fx_s1(i) =  0.26765*x_int1;% + 0.0142;

fz_s2(i) = 0.64248*z_int2 ;%-0.023685;
fy_s2(i) = 0.15159*y_int2;%-0.20725;
fx_s2(i) =  0.13342*x_int2 ;%+ 0.33024 ;


[fx_s1(i) fy_s1(i) fz_s1(i) x_ne1 fx_s2(i) fy_s2(i) fz_s2(i)]




end








