%clear all
cam1 = webcam(1);
cam2 = webcam(2);
cam2.Resolution = '1280x720';
for i = 1:1:400
y_img = snapshot(cam1);
img = snapshot(cam2);

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

z_ini_s3(i) = mean(mean(rgb2gray(y_img(235:283,312:337,:))));
yp_ini_s3(i) =  mean(mean(rgb2gray(y_img(289:327,275:308,:))));
xp_ini_s3(i) =  mean(mean(rgb2gray(y_img(207:240,266:300,:))));

z_ini_s4(i) = mean(mean(rgb2gray(y_img(104:127,434:448,:))));
yn_ini_s4(i) =  mean(mean(rgb2gray(y_img(62:83,456:483,:))));
xp_ini_s4(i) =  mean(mean(rgb2gray(y_img(57:94,389:420,:))));

z_ini_s5(i) = mean(mean(rgb2gray(y_img(138:151,186:198,:))));
yn_ini_s5(i) =  mean(mean(rgb2gray(y_img(92:115,206:233,:))));
xp_ini_s5(i) =  mean(mean(rgb2gray(y_img(163:195,215:239,:))));

z_ini_s6(i) = mean(mean(rgb2gray(y_img(401:416,211:225,:))));
yp_ini_s6(i) =  mean(mean(rgb2gray(y_img(367:388,230:257,:))));
xp_ini_s6(i) =  mean(mean(rgb2gray(y_img(451:462,238:281,:))));

z_ini_s7(i) = mean(mean(rgb2gray(y_img(370:382,480:489,:))));
yp_ini_s7(i) =  mean(-mean(rgb2gray(y_img(409:426,437:459,:))));
xp_ini_s7(i) = mean(mean(rgb2gray(y_img(397:417,519:531,:))));
i

end

initial_y_po1 = mean(y_po_ini1(100:400));
initial_y_ne1 = mean(y_ne_ini1(100:400));
initial_x_po1 = mean(x_po_ini1(100:400));
initial_x_ne1 = mean(x_ne_ini1(100:400));
initial_z1 = mean(z_po_ini1(100:400));


initial_y_po2 = mean(y_po_ini2(100:400));
initial_y_ne2 = mean(y_ne_ini2(100:400));
initial_x_po2 = mean(x_po_ini2(100:400));
initial_x_ne2 = mean(x_ne_ini2(100:400));
initial_z2 = mean(z_po_ini2(100:400));

z_s3_initial = mean(z_ini_s3(100:400));
y_s3_initial = mean(yp_ini_s3(100:400));
x_s3_initial = mean(xp_ini_s3(100:400)); 

z_s4_initial = mean(z_ini_s4(100:400));
y_s4_initial = mean(yn_ini_s4(100:400));
x_s4_initial = mean(xp_ini_s4(100:400)); 

z_s5_initial = mean(z_ini_s5(100:400));
y_s5_initial = mean(yn_ini_s5(100:400));
x_s5_initial = mean(xp_ini_s5(100:400)); 

z_s6_initial = mean(z_ini_s6(100:400));
y_s6_initial = mean(yp_ini_s6(100:400));
x_s6_initial = mean(xp_ini_s6(100:200)); 

z_s7_initial = mean(z_ini_s7(100:400));
y_s7_initial = mean(yp_ini_s7(100:400));
x_s7_initial = mean(xp_ini_s7(100:400)); 

for i = 1:1:100
    
y_img = snapshot(cam1);
img = snapshot(cam2);

y_po1(i) = mean(mean(rgb2gray(img(286:339,768:831,:)))) - initial_y_po1;
y_ne1(i) = mean(mean(rgb2gray(img(157:231,962:1052,:)))) - initial_y_ne1;
x_po1(i) = mean(mean(rgb2gray(img(297:369,900:968,:)))) - initial_x_po1;
x_ne1(i) = mean(mean(rgb2gray(img(159:214,805:876,:)))) - initial_x_ne1;
z_po1(i) =  -(mean(mean(rgb2gray(img(233:272,864:933,:)))) - initial_z1);

y_po2(i) = mean(mean(rgb2gray(img(561:637,269:358,:)))) - initial_y_po2;
y_ne2(i) = mean(mean(rgb2gray(img(450:502,494:553,:)))) - initial_y_ne2;
x_po2(i) = mean(mean(rgb2gray(img(589:683,440:523,:)))) - initial_x_po2;
x_ne2(i) = mean(mean(rgb2gray(img(425:474,353:422,:)))) - initial_x_ne2;
z_po2(i) =  -(mean(mean(rgb2gray(img(503:563,393:456,:)))) - initial_z2);

z_li_s3(i) = mean(mean(rgb2gray(y_img(235:283,312:337,:)))) - z_s3_initial;
y_li_s3(i) =  mean(mean(rgb2gray(y_img(289:327,275:308,:))))- y_s3_initial;
x_li_s3(i) =  mean(mean(rgb2gray(y_img(207:240,266:300,:))))- x_s3_initial;

z_li_s4(i) = mean(mean(rgb2gray(y_img(104:127,434:448,:))))- z_s4_initial;
y_li_s4(i) =  mean(mean(rgb2gray(y_img(62:83,456:483,:))))- y_s4_initial;
x_li_s4(i) =  mean(mean(rgb2gray(y_img(57:94,389:420,:))))- x_s4_initial;

z_li_s5(i) = mean(mean(rgb2gray(y_img(138:151,186:198,:))))- z_s5_initial;
y_li_s5(i) =  mean(mean(rgb2gray(y_img(92:115,206:233,:))))- y_s5_initial;
x_li_s5(i) =  mean(mean(rgb2gray(y_img(163:195,215:239,:))))- x_s5_initial;
 
z_li_s6(i) = mean(mean(rgb2gray(y_img(401:416,211:225,:)))) - z_s6_initial;
y_li_s6(i) =  mean(mean(rgb2gray(y_img(367:388,230:257,:)))) - y_s6_initial;
x_li_s6(i) =  mean(mean(rgb2gray(y_img(451:462,238:281,:)))) - x_s6_initial;

z_li_s7(i) = mean(mean(rgb2gray(y_img(370:382,480:489,:))))- z_s7_initial;
y_li_s7(i) =  -mean(mean(rgb2gray(y_img(409:426,437:459,:))))- y_s7_initial;
x_li_s7(i) = mean(mean(rgb2gray(y_img(397:417,519:531,:))))- x_s7_initial;

if (i>7 && i<20)
    
 liz_s1 = mean( [z_po1(i-5:i-1) z_po1(i)]);
 lix_po_s1 = mean( [x_po1(i-5:i-1) x_po1(i)]);
 lix_ne_s1 = mean( [x_ne1(i-5:i-1) x_ne1(i)]);
 liy_po_s1 = mean( [y_po1(i-5:i-1) y_po1(i)]);
 liy_ne_s1 = mean( [y_ne1(i-5:i-1) y_ne1(i)]);
 
 liz_s2 = mean( [z_po2(i-5:i-1) z_po2(i)]);
 lix_po_s2 = mean( [x_po2(i-5:i-1) x_po2(i)]);
 lix_ne_s2 = mean( [x_ne2(i-5:i-1) x_ne2(i)]);
 liy_po_s2 = mean( [y_po2(i-5:i-1) y_po2(i)]);
 liy_ne_s2 = mean( [y_ne2(i-5:i-1) y_ne2(i)]);
     
 liz_s3 = mean( [z_li_s3(i-5:i-1) z_li_s3(i)]);
 lix_s3 = mean( [x_li_s3(i-5:i-1) x_li_s3(i)]);
 liy_s3 = mean( [y_li_s3(i-5:i-1) y_li_s3(i)]);
 
 liz_s4 = mean( [z_li_s4(i-5:i-1) z_li_s4(i)]);
 lix_s4 = mean( [x_li_s4(i-5:i-1) x_li_s4(i)]);
 liy_s4 = mean( [y_li_s4(i-5:i-1) y_li_s4(i)]);
 
 liz_s5 = mean( [z_li_s5(i-5:i-1) z_li_s5(i)]);
 lix_s5 = mean( [x_li_s5(i-5:i-1) x_li_s5(i)]);
 liy_s5 = mean( [y_li_s5(i-5:i-1) y_li_s5(i)]);
 
 liz_s6 = mean( [z_li_s6(i-5:i-1) z_li_s6(i)]);
 lix_s6 = mean( [x_li_s6(i-5:i-1) x_li_s6(i)]);
 liy_s6 = mean( [y_li_s6(i-5:i-1) y_li_s6(i)]);
 
 liz_s7 = mean( [z_li_s7(i-5:i-1) z_li_s7(i)]);
 lix_s7 = mean( [x_li_s7(i-5:i-1) x_li_s7(i)])
 liy_s7 = mean( [y_li_s7(i-5:i-1) y_li_s7(i)]);
 

y_int1 = liy_po_s1- liy_ne_s1;
z_int1 = liz_s1;

if (lix_ne_s1<0)
   x_int1 = lix_ne_s1;
else
   x_int1 =  lix_po_s1;
end

y_int2 = liy_po_s2-liy_ne_s2;
x_int2 = lix_po_s2-lix_ne_s2;
z_int2 = liz_s2;

%%%% sensor 1 Final calibration 
fz_s1f(i) = 0.0027052*z_int1^4 -0.011676*z_int1^3 -0.010948*z_int1^2 + 0.71242*z_int1  -0.004521;
fy_s1f(i) = 0.095471*y_int1;% + 0.30823;
fx_s1f(i) =  0.26765*x_int1;% + 0.0142;

%%%% sensor 2 Final calibration 
fz_s2f(i) = 0.64248*z_int2 ;%-0.023685;
fy_s2f(i) = 0.15159*y_int2;%-0.20725;
fx_s2f(i) =  0.13342*x_int2 ;%+ 0.33024 ;

%%%% sensor 3 Final calibration 
fz_s3f(i) = -0.011222* liz_s3^3 + -0.043049* liz_s3^2 -0.93763* liz_s3 + 0.0071904;
fy_s3f(i) = 3.8712e-05* liy_s3^3 + -0.0028025* liy_s3^2 + 0.16335* liy_s3 -0.16775;
fx_s3f(i) = 1.8035e-05* lix_s3^3 -0.0023924* lix_s3^2 + 0.26868* lix_s3 +0.04158 ;

%%%% sensor4 Final calibration 
fz_s4f(i) = -0.011222* liz_s4^3 + -0.043049* liz_s4^2 -0.93763* liz_s4 + 0.0071904;
fy_s4f(i) = -2.5286e-05*liy_s4^4 + -0.0015057*liy_s4^3 + -0.026599*liy_s4^2 +0.075347*liy_s4 + 0.021047;
fx_s4f(i) = -0.00017878* lix_s4^3  -0.0079705* lix_s4^2 -0.3129* lix_s4 -0.67847;

%%%% sensor5 Final calibration 
fz_s5f(i) = -0.0044725* liz_s5^3-0.047633* liz_s5^2 -0.46121* liz_s5 + 0.73707;
fy_s5f(i) = -1.0017e-12* liy_s5^10 + 8.9623e-11* liy_s5^9 + -1.9142e-09* liy_s5^8 + -4.0429e-08* liy_s5^7 + 1.8078e-06* liy_s5^6 + -4.7217e-06* liy_s5^5 +-0.00042256* liy_s5^4 + 0.0030408* liy_s5^3 + 0.043865* liy_s5^2 +  -0.7219* liy_s5;
fx_s5f(i) =0.011346*lix_s5^3 + 0.16438*lix_s5^2+0.98549*lix_s5 +0.017546;
 
%%%% sensor6 Final calibration
fz_s6f(i) = 0.00022378* liz_s6^4 + -0.0061643* liz_s6^3 +0.034503* liz_s6^2 + 0.48075* liz_s6 +  0.048943;
fy_s6f(i) = 5.0291e-05*liy_s6^3 -0.00078962*liy_s6^2+0.15164*liy_s6 +0.0049077;
fx_s6f(i) =-2.3331e-06*lix_s6^4 +-6.2271e-05*lix_s6^3 + 0.0022352*lix_s6^2 +0.30789*lix_s6 + 0.42283;

%%% sensor7 Final calibration
fz_s7f(i) = -0.0017082*liz_s7^3 -0.033597*liz_s7^2 -0.49547*liz_s7 -0.030753 ;
fy_s7f(i) = 7.939e-07*liy_s7^4 + -1.6693e-05*liy_s7^3 -0.0038142*liy_s7^2 +-0.20008*liy_s7 + 0.096795;   %%%5 best one!
fx_s7f(i) =0.0006545*lix_s7^3-0.026066*lix_s7^2 +  0.52242*lix_s7 +0.032173;


elseif ( i>20)
        
 liz_s1 = mean( [z_po1(i-5:i-1) z_po1(i)]);
 lix_po_s1 = mean( [x_po1(i-5:i-1) x_po1(i)]);
 lix_ne_s1 = mean( [x_ne1(i-5:i-1) x_ne1(i)]);
 liy_po_s1 = mean( [y_po1(i-5:i-1) y_po1(i)]);
 liy_ne_s1 = mean( [y_ne1(i-5:i-1) y_ne1(i)]);
 
 liz_s2 = mean( [z_po2(i-5:i-1) z_po2(i)]);
 lix_po_s2 = mean( [x_po2(i-5:i-1) x_po2(i)]);
 lix_ne_s2 = mean( [x_ne2(i-5:i-1) x_ne2(i)]);
 liy_po_s2 = mean( [y_po2(i-5:i-1) y_po2(i)]);
 liy_ne_s2 = mean( [y_ne2(i-5:i-1) y_ne2(i)]);
        
 liz_s3 = mean( [z_li_s3(i-5:i-1) z_li_s3(i)]);
 lix_s3 = mean( [x_li_s3(i-5:i-1) x_li_s3(i)]);
 liy_s3 = mean( [y_li_s3(i-5:i-1) y_li_s3(i)]);
 
 liz_s4 = mean( [z_li_s4(i-5:i-1) z_li_s4(i)]);
 lix_s4 = mean( [x_li_s4(i-5:i-1) x_li_s4(i)]);
 liy_s4 = mean( [y_li_s4(i-5:i-1) y_li_s4(i)]);
 
 liz_s5 = mean( [z_li_s5(i-5:i-1) z_li_s5(i)]);
 lix_s5 = mean( [x_li_s5(i-5:i-1) x_li_s5(i)]);
 liy_s5 = mean( [y_li_s5(i-5:i-1) y_li_s5(i)]);
 
 liz_s6 = mean( [z_li_s6(i-5:i-1) z_li_s6(i)]);
 lix_s6 = mean( [x_li_s6(i-5:i-1) x_li_s6(i)]);
 liy_s6 = mean( [y_li_s6(i-5:i-1) y_li_s6(i)]);
 
 liz_s7 = mean( [z_li_s7(i-5:i-1) z_li_s7(i)]);
 lix_s7 = mean( [x_li_s7(i-5:i-1) x_li_s7(i)]);
 liy_s7 = mean( [y_li_s7(i-5:i-1) y_li_s7(i)]);
    

y_int1 = liy_po_s1- liy_ne_s1;
z_int1 = liz_s1;

if (lix_ne_s1<0)
   x_int1 = lix_ne_s1;
else
   x_int1 =  lix_po_s1;
end



y_int2 = liy_po_s2-liy_ne_s2;
x_int2 = lix_po_s2-lix_ne_s2;
z_int2 = liz_s2;
%%%% sensor 1 Final calibration 
fz_s1 = 0.0027052*z_int1^4 -0.011676*z_int1^3 -0.010948*z_int1^2 + 0.71242*z_int1-0.004521- mean(fz_s1f(8:19));
fy_s1 = 0.095471*y_int1- mean(fy_s1f(8:19));% + 0.30823;
fx_s1 =  0.26765*x_int1- mean(fx_s1f(8:19));% + 0.0142;

%%%% sensor 2 Final calibration 
fz_s2 = 0.64248*z_int2- mean(fz_s2f(8:19));%-0.023685;
fy_s2 = 0.15159*y_int2- mean(fy_s2f(8:19));%-0.20725;
fx_s2 =  0.13342*x_int2- mean(fx_s2f(8:19));%+ 0.33024 ;

%%%% sensor 3 Final calibration 
fz_s3 = -0.011222* liz_s3^3 + -0.043049* liz_s3^2 -0.93763* liz_s3 + 0.0071904 - mean(fz_s3f(8:19));
fy_s3 = 3.8712e-05* liy_s3^3 + -0.0028025* liy_s3^2 + 0.16335* liy_s3 -0.16775- mean(fy_s3f(8:19));
fx_s3 = 1.8035e-05* lix_s3^3 -0.0023924* lix_s3^2 + 0.26868* lix_s3 +0.04158- mean(fx_s3f(8:19));

%%%% sensor4 Final calibration 
fz_s4 = -0.011222* liz_s4^3 + -0.043049* liz_s4^2 -0.93763* liz_s4 + 0.0071904- mean(fz_s4f(8:19));
fy_s4 = -2.5286e-05*liy_s4^4 + -0.0015057*liy_s4^3 + -0.026599*liy_s4^2 +0.075347*liy_s4 + 0.021047- mean(fy_s4f(8:19));
fx_s4 = -0.00017878* lix_s4^3  -0.0079705* lix_s4^2 -0.3129* lix_s4 -0.67847- mean(fx_s4f(8:19));

%%%% sensor5 Final calibration 
fz_s5 = -0.0044725* liz_s5^3-0.047633* liz_s5^2 -0.46121* liz_s5 + 0.73707- mean(fz_s5f(8:19));
fy_s5 = (-1.0017e-12* liy_s5^10 + 8.9623e-11* liy_s5^9 + -1.9142e-09* liy_s5^8 + -4.0429e-08* liy_s5^7 + 1.8078e-06* liy_s5^6 + -4.7217e-06* liy_s5^5 +-0.00042256* liy_s5^4 + 0.0030408* liy_s5^3 + 0.043865* liy_s5^2 +  -0.7219* liy_s5- mean(fy_s5f(8:19)))*2;
fx_s5 = 0.011346*lix_s5^3 + 0.16438*lix_s5^2+0.98549*lix_s5 +0.017546- mean(fx_s5f(8:19));

%%%% sensor6 Final calibration
fz_s6 = 0.00022378* liz_s6^4 + -0.0061643* liz_s6^3 +0.034503* liz_s6^2 + 0.48075* liz_s6 +  0.048943- mean(fz_s6f(8:19));
fy_s6 = (5.0291e-05*liy_s6^3 -0.00078962*liy_s6^2+0.15164*liy_s6 +0.0049077- mean(fy_s6f(8:19)));
fx_s6 = -2.3331e-06*lix_s6^4 +-6.2271e-05*lix_s6^3 + 0.0022352*lix_s6^2 +0.30789*lix_s6 + 0.42283 - mean(fx_s6f(8:19));

%%% sensor7 Final calibration
fz_s7 = -0.0017082*liz_s7^3 -0.033597*liz_s7^2 -0.49547*liz_s7 -0.030753 - mean(fz_s7f(8:19));
fy_s7 =( 7.939e-07*liy_s7^4 + -1.6693e-05*liy_s7^3 -0.0038142*liy_s7^2 +-0.20008*liy_s7 + 0.096795- mean(fy_s7f(8:19)))*3;   %%%5 best one!
fx_s7 =0.0006545*lix_s7^3-0.026066*lix_s7^2 +  0.52242*lix_s7 +0.032173 - mean(fx_s7f(8:19));


Force(i,:) = [fx_s1 fy_s1 fz_s1 fx_s2 fy_s2 fz_s2 fx_s3 fy_s3 fz_s3 fx_s4 fy_s4 fz_s4 fx_s5 fy_s5 fz_s5 fx_s6 fy_s6 fz_s6 fx_s7 fy_s7 fz_s7];




end
i = i+1;
end

