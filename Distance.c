/*distance
        1.CM [CENTIMETERS]
        2.M  [METERS]
        3.KM [KILO-METERS]
        4.MI [MILES]
        5.IN [INCHES]
        6.FT [FOOT]
        7.YD [YARDS]
*/
//                      CM          M           KM          MI          IN          FT      YD
float Distance[7][7]={{ 1       , 0.01      , 0.00001   , 0.000006  , 0.3937    , 0.0328 , 0.010936 },//CM
                      { 100     , 1         , 0.001     , 0.00062   , 39.37     , 3.28   , 1.0936   },//M
                      {100000   , 1000      , 1         , 0.6213    , 39370.078 , 3280.84 , 1093.6133},//KM
                      {160934.4 , 1609.344  , 1.609344  , 1         , 63360     , 5280   , 1760     },//MI
                      {2.54     , 0.0254    , 0.0000025 , 0.0000015 , 1         , 0.0833 , 0.02778  },//IN
                      {30.48    , 0.3048    , 0.000305  , 0.00019   , 12        , 1      , 0.333333 },//FT
                      {91.44    , 0.9144    , 0.0009144 , 0.000568  , 36        , 3      , 1        }};//YD

float Distance_Conversion(float value, int present_value, int Conv_value)
{
    return value*Distance[present_value-1][Conv_value-1];
}
