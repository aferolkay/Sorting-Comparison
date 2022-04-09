N=[100 1000 5000 10000 25000];
bubbleC=[4728       495351 12482245  49952985  312307796   ];
bubbleM=[7525     743703 18737358     75245065  NaN];
bubbleT=[0.01632 1.628 41.589 182.3 1417.25];

selectionC=[4950 499500 12497500  49995000   312487500  ];
selectionM=[297  2997 14997     29997   74997];
selectionT=[0.01228 1.092  25.999   103.366   644.288   ];

quick1C=[928 15181 99496 215002 615656            ];
quick1M=[496 7110 43831 95146 260388     ];
quick1T=[0.00206 0.053  0.423  0.9 2.468];

quick2C=[887 13065   45968   179595   501807  ];
quick2M=[547  7699  47437   101031 280109      ];
quick2T=[0.0018 0.05   0.415    0.895  2.376 ];


quick3C=[907             13852   82503  184200  501807               ];
quick3M=[564  7879  47678   102303 281884           ];
quick3T=[0.007 0.091   0.502    1.063  2.804 ];

quick4C=[810 11873   74436   162624   442667              ];
quick4M=[570  8044  48720   105208    289057           ];
quick4T=[0.0097 0.119  0.646    1.351  3.52 ];

ownC=[770 12466  80299  173236 316249];
ownM=[679 9252 54955  114778   309473];
ownT=[0.00146 0.031 0.335 0.738 1.992];

figure;
semilogy(N,bubbleC,'Marker','o','LineWidth',4);
hold on;
semilogy(N,selectionC,'Marker','o','LineWidth',2);
semilogy(N,quick1C,'Marker','o','LineWidth',2);
semilogy(N,quick2C,'Marker','o','LineWidth',2);
semilogy(N,quick3C,'Marker','o','LineWidth',2);
semilogy(N,quick4C,'Marker','o','LineWidth',2);
semilogy(N,ownC,'Marker','o','LineWidth',2);
legend("Bubble","Selection","Quick1","Quick2","Quick3","Quick4","Own Sort");
ylabel("#comparisons");
xlabel("# of elements");
title("#comparisons of algorithms");

figure;
semilogy(N,bubbleM,'Marker','o','LineWidth',2);
hold on;
semilogy(N,selectionM,'Marker','o','LineWidth',2);
semilogy(N,quick1M,'Marker','o','LineWidth',2);
semilogy(N,quick2M,'Marker','o','LineWidth',2);
semilogy(N,quick3M,'Marker','o','LineWidth',2);
semilogy(N,quick4M,'Marker','o','LineWidth',2);
semilogy(N,ownM,'Marker','o','LineWidth',2);
legend("Bubble","Selection","Quick1","Quick2","Quick3","Quick4","Own Sort");
ylabel("#moves");
xlabel("# of elements");
title("#moves of algorithms");

figure;
semilogy(N,bubbleT,'Marker','o','LineWidth',2);
hold on;
semilogy(N,selectionT,'Marker','o','LineWidth',2);
semilogy(N,quick1T,'Marker','o','LineWidth',2);
semilogy(N,quick2T,'Marker','o','LineWidth',2);
semilogy(N,quick3T,'Marker','o','LineWidth',2);
semilogy(N,quick4T,'Marker','o','LineWidth',2);
semilogy(N,ownT,'Marker','o','LineWidth',2);
legend("Bubble","Selection","Quick1","Quick2","Quick3","Quick4","Own Sort");
ylabel("elapsed time");
xlabel("# of elements");
title("time of execution of algorithms");



