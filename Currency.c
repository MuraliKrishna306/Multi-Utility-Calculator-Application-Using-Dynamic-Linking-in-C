/*currency 
        1.INR [INDIAN RUPEE] 
        2.USD[UNITED STATES] 
        3.EUR [EURO] 
        4.JPY [JAPANESE YEN] 
        5.GBP [BRITISH POUND STERLING] 
        6.AUD [AUSTRALIA] 
        7.CAD [CANADIAN DOLLAR] 
        8.CNY [CHINESE YUAN] 
        9.AED [DIRHAM-UAE]
*/
//                     INR         USD     EURO      JPY       GBP     AUD       CAD     CNY       AED
float Currency[9][9]={{ 1        , 0.0113 , 0.0097 , 1.7304 , 0.0086 , 0.0174 , 0.0158 , 0.0803 , 0.0414 },//INR
                      { 88.665   , 1      , 0.8646 , 153.43 , 0.7598 , 1.54   , 1.405  , 7.1226 , 3.67   },//USD
                      { 102.6709 , 1.1566 , 1      , 177.46 , 0.879  , 1.781  , 1.625  , 8.2364 , 4.2483 },//EUR
                      { 0.58     , 0.0065 , 0.0056 , 1      , 0.005  , 0.01   , 0.009  , 0.0464 , 0.024  },//JPY
                      { 116.7    , 1.316  , 1.138  , 201.93 , 1      , 2.026  , 1.85   , 9.3752 , 4.8342 },//GBP
                      { 57.58    , 0.65   , 0.5615 , 99.64  , 0.5    , 1      , 0.9123 , 4.625  , 2.3853 },//AUD
                      { 63.1135  , 0.7118 , 0.6155 , 109.21 , 0.541  , 1.096  , 1      , 5.07   , 2.6145 },//CAD
                      { 12.448   , 0.14   , 0.1214 , 21.54  , 0.1067 , 0.2162 , 0.197  , 1      , 0.515  },//CNY
                      { 24.14    , 0.272  , 0.235  , 41.769 , 0.207  , 0.419  , 0.3825 , 1.9391 , 1      }};//AED

float Currency_conversion(float value, int present_currency, int Conv_currency)
{
    return value*Currency[present_currency-1][Conv_currency-1];
}

