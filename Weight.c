/* Weight
        1.KG [KILO-GRAMS]
        2.G  [GRAMS]
        3.MG [MILLI-GRAMS]
        4.Q  [QUINTAL]
        5.LB [POUNDS]
*/
//                      KG      G           MG          Q               LB
float Weight[5][5]={{1        , 1000     , 1000000   , 0.01       , 2.2046   },//KG
                    {0.001    , 1        , 1000      , 0.00001    , 0.0022   },//G
                    {0.000001 , 0.001    , 1         , 0.00000001 , 0.000022 },//MG
                    {100      , 100000   , 100000000 , 1          , 220.4622 },//Q
                    {0.4535   , 453.5937 , 458592.37 , 0.004535   , 1       }};//LB

float Weight_Conversion(float value , int Present_value , int Conv_value)
{
    return value*Weight[Present_value-1][Conv_value-1];
}

