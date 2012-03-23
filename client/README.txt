    //Leer configuracion del INI
        //get user info
        //get stats
        //get categorys

    //OnConnect
       connect to the server to get total data from each category,
       then, when a user click the trayicon, the program will show
        a window with data from the following algorithm:rand(totalINcaT)
        when the data gets,is saved in a cache so, the next time, the client
        wont call to webservice.
        [ONCONNECT
           | CHECK USER
               + IF EXISTS
                    | GET TOTAL ROWS OF EACH CAT > $COUNTS
               + ELSE
                    - error
        ]
        [ONICONCLICK
           | CHECK LOG IN
               + IF EXISTS
                    =>ROW_ID:RAND(TOTAL_RIN_CAT)
                    =>CAT_ID:RAND(LOCALOPTION_CATS)
                    | WITH CAT_ID CHECK IF DATA EXISTS IN CACHE: CAT_ID.TXT|ROW_ID
                        + IF EXISTS
                            | GET DATA FROM CACHE AND SHOW
                        + ELSE
                            | GET DATA,SHOW AND SAVE IN CACHE CACHE
               + ELSE
                    - error
        ]
