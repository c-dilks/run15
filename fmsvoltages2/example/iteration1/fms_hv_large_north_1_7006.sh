#!/bin/bash
t=`date +%Y.%h.%d-%H.%d.%S`
(
sleep 2;
echo -e "\r";
sleep 1;
echo -e "read (0-15,0-15) \r";
sleep 5;
echo -e "set voltage limit 1600 \r";
echo -e "\r";
echo -e "write (0-15,0-15) -900\r"; sleep 2;

echo -e "write (0,0) -1398\r"; sleep 2;
echo -e "write (0,1) -1403\r"; sleep 2;
echo -e "write (0,2) -1466\r"; sleep 2;
echo -e "write (0,3) -1562\r"; sleep 2;
echo -e "write (0,4) -1562\r"; sleep 2;
echo -e "write (0,5) -1439\r"; sleep 2;
echo -e "write (0,6) -1599\r"; sleep 2;
echo -e "write (0,9) -1417\r"; sleep 2;
echo -e "write (0,10) -1595\r"; sleep 2;
echo -e "write (0,11) -1432\r"; sleep 2;
echo -e "write (0,12) -1552\r"; sleep 2;
echo -e "write (0,13) -1429\r"; sleep 2;
echo -e "write (0,14) -1481\r"; sleep 2;
echo -e "write (1,0) -1446\r"; sleep 2;
echo -e "write (1,1) -1449\r"; sleep 2;
echo -e "write (1,2) -1239\r"; sleep 2;
echo -e "write (1,3) -1344\r"; sleep 2;
echo -e "write (1,4) -1501\r"; sleep 2;
echo -e "write (1,5) -1245\r"; sleep 2;
echo -e "write (1,6) -1579\r"; sleep 2;
echo -e "write (1,9) -1385\r"; sleep 2;
echo -e "write (1,10) -1568\r"; sleep 2;
echo -e "write (1,11) -1591\r"; sleep 2;
echo -e "write (1,12) -1379\r"; sleep 2;
echo -e "write (1,13) -1566\r"; sleep 2;
echo -e "write (1,14) -1427\r"; sleep 2;
echo -e "write (2,0) -1548\r"; sleep 2;
echo -e "write (2,1) -1327\r"; sleep 2;
echo -e "write (2,2) -1551\r"; sleep 2;
echo -e "write (2,3) -1491\r"; sleep 2;
echo -e "write (2,4) -1520\r"; sleep 2;
echo -e "write (2,5) -1504\r"; sleep 2;
echo -e "write (2,6) -1537\r"; sleep 2;
echo -e "write (2,9) -1383\r"; sleep 2;
echo -e "write (2,10) -1516\r"; sleep 2;
echo -e "write (2,11) -1347\r"; sleep 2;
echo -e "write (2,12) -1316\r"; sleep 2;
echo -e "write (2,14) -1302\r"; sleep 2;
echo -e "write (3,0) -1596\r"; sleep 2;
echo -e "write (3,1) -1286\r"; sleep 2;
echo -e "write (3,2) -1305\r"; sleep 2;
echo -e "write (3,3) -1214\r"; sleep 2;
echo -e "write (3,4) -1304\r"; sleep 2;
echo -e "write (3,5) -1335\r"; sleep 2;
echo -e "write (3,6) -1323\r"; sleep 2;
echo -e "write (3,9) -1459\r"; sleep 2;
echo -e "write (3,10) -1519\r"; sleep 2;
echo -e "write (3,11) -1513\r"; sleep 2;
echo -e "write (3,12) -1478\r"; sleep 2;
echo -e "write (3,13) -1545\r"; sleep 2;
echo -e "write (3,14) -1534\r"; sleep 2;
echo -e "write (4,0) -1488\r"; sleep 2;
echo -e "write (4,1) -1462\r"; sleep 2;
echo -e "write (4,2) -1480\r"; sleep 2;
echo -e "write (4,3) -1493\r"; sleep 2;
echo -e "write (4,4) -1512\r"; sleep 2;
echo -e "write (4,5) -1456\r"; sleep 2;
echo -e "write (4,6) -1541\r"; sleep 2;
echo -e "write (4,9) -1477\r"; sleep 2;
echo -e "write (4,10) -1530\r"; sleep 2;
echo -e "write (4,11) -1441\r"; sleep 2;
echo -e "write (4,12) -1505\r"; sleep 2;
echo -e "write (4,13) -1467\r"; sleep 2;
echo -e "write (4,14) -1572\r"; sleep 2;
echo -e "write (5,0) -1497\r"; sleep 2;
echo -e "write (5,1) -1482\r"; sleep 2;
echo -e "write (5,2) -1493\r"; sleep 2;
echo -e "write (5,3) -1431\r"; sleep 2;
echo -e "write (5,4) -1492\r"; sleep 2;
echo -e "write (5,5) -1515\r"; sleep 2;
echo -e "write (5,6) -1405\r"; sleep 2;
echo -e "write (5,9) -1266\r"; sleep 2;
echo -e "write (5,10) -1429\r"; sleep 2;
echo -e "write (5,11) -1596\r"; sleep 2;
echo -e "write (5,12) -1412\r"; sleep 2;
echo -e "write (5,13) -1526\r"; sleep 2;
echo -e "write (5,14) -1532\r"; sleep 2;
echo -e "write (6,0) -1416\r"; sleep 2;
echo -e "write (6,1) -1526\r"; sleep 2;
echo -e "write (6,2) -1443\r"; sleep 2;
echo -e "write (6,3) -1479\r"; sleep 2;
echo -e "write (6,4) -1563\r"; sleep 2;
echo -e "write (6,5) -1445\r"; sleep 2;
echo -e "write (6,6) -1473\r"; sleep 2;
echo -e "write (6,9) -1558\r"; sleep 2;
echo -e "write (6,10) -1524\r"; sleep 2;
echo -e "write (6,11) -1576\r"; sleep 2;
echo -e "write (6,12) -1528\r"; sleep 2;
echo -e "write (6,13) -1420\r"; sleep 2;
echo -e "write (6,14) -1418\r"; sleep 2;
echo -e "write (7,0) -1180\r"; sleep 2;
echo -e "write (7,1) -1537\r"; sleep 2;
echo -e "write (7,2) -1509\r"; sleep 2;
echo -e "write (7,3) -1311\r"; sleep 2;
echo -e "write (7,4) -1486\r"; sleep 2;
echo -e "write (7,5) -1240\r"; sleep 2;
echo -e "write (7,6) -1571\r"; sleep 2;
echo -e "write (7,9) -1448\r"; sleep 2;
echo -e "write (7,10) -1427\r"; sleep 2;
echo -e "write (7,11) -1422\r"; sleep 2;
echo -e "write (7,12) -1341\r"; sleep 2;
echo -e "write (7,13) -1449\r"; sleep 2;
echo -e "write (7,14) -1473\r"; sleep 2;
echo -e "write (8,0) -1251\r"; sleep 2;
echo -e "write (8,1) -1527\r"; sleep 2;
echo -e "write (8,2) -1350\r"; sleep 2;
echo -e "write (8,3) -1393\r"; sleep 2;
echo -e "write (8,4) -1273\r"; sleep 2;
echo -e "write (8,5) -1307\r"; sleep 2;
echo -e "write (8,6) -1225\r"; sleep 2;
echo -e "write (8,9) -1411\r"; sleep 2;
echo -e "write (8,10) -1383\r"; sleep 2;
echo -e "write (8,11) -1305\r"; sleep 2;
echo -e "write (8,12) -1167\r"; sleep 2;
echo -e "write (8,13) -1196\r"; sleep 2;
echo -e "write (8,14) -1463\r"; sleep 2;
echo -e "write (9,0) -1426\r"; sleep 2;
echo -e "write (9,1) -1452\r"; sleep 2;
echo -e "write (9,2) -1528\r"; sleep 2;
echo -e "write (9,3) -1328\r"; sleep 2;
echo -e "write (9,4) -1316\r"; sleep 2;
echo -e "write (9,5) -1388\r"; sleep 2;
echo -e "write (9,6) -1383\r"; sleep 2;
echo -e "write (9,9) -1437\r"; sleep 2;
echo -e "write (9,10) -1460\r"; sleep 2;
echo -e "write (9,11) -1564\r"; sleep 2;
echo -e "write (9,12) -1429\r"; sleep 2;
echo -e "write (9,13) -1489\r"; sleep 2;
echo -e "write (9,14) -1418\r"; sleep 2;
echo -e "write (10,0) -1581\r"; sleep 2;
echo -e "write (10,1) -1578\r"; sleep 2;
echo -e "write (10,2) -1427\r"; sleep 2;
echo -e "write (10,3) -1418\r"; sleep 2;
echo -e "write (10,4) -1378\r"; sleep 2;
echo -e "write (10,5) -1442\r"; sleep 2;
echo -e "write (10,6) -1536\r"; sleep 2;
echo -e "write (10,9) -1469\r"; sleep 2;
echo -e "write (10,10) -1320\r"; sleep 2;
echo -e "write (10,11) -1486\r"; sleep 2;
echo -e "write (10,12) -1436\r"; sleep 2;
echo -e "write (10,13) -1257\r"; sleep 2;
echo -e "write (10,14) -1453\r"; sleep 2;
echo -e "write (11,0) -1496\r"; sleep 2;
echo -e "write (11,1) -1592\r"; sleep 2;
echo -e "write (11,2) -1567\r"; sleep 2;
echo -e "write (11,3) -1196\r"; sleep 2;
echo -e "write (11,4) -1291\r"; sleep 2;
echo -e "write (11,5) -1314\r"; sleep 2;
echo -e "write (11,6) -1208\r"; sleep 2;
echo -e "write (11,9) -1389\r"; sleep 2;
echo -e "write (11,10) -1230\r"; sleep 2;
echo -e "write (11,11) -1272\r"; sleep 2;
echo -e "write (11,12) -1235\r"; sleep 2;
echo -e "write (11,13) -1268\r"; sleep 2;
echo -e "write (11,14) -1368\r"; sleep 2;
echo -e "write (12,0) -1336\r"; sleep 2;
echo -e "write (12,1) -1160\r"; sleep 2;
echo -e "write (12,2) -1490\r"; sleep 2;
echo -e "write (12,3) -1459\r"; sleep 2;
echo -e "write (12,4) -1419\r"; sleep 2;
echo -e "write (12,5) -1372\r"; sleep 2;
echo -e "write (12,6) -1314\r"; sleep 2;
echo -e "write (12,9) -1367\r"; sleep 2;
echo -e "write (12,10) -1360\r"; sleep 2;
echo -e "write (12,11) -1583\r"; sleep 2;
echo -e "write (12,12) -1572\r"; sleep 2;
echo -e "write (12,13) -1432\r"; sleep 2;
echo -e "write (12,14) -1583\r"; sleep 2;
echo -e "write (13,0) -1517\r"; sleep 2;
echo -e "write (13,1) -1464\r"; sleep 2;
echo -e "write (13,2) -1541\r"; sleep 2;
echo -e "write (13,3) -1250\r"; sleep 2;
echo -e "write (13,4) -1430\r"; sleep 2;
echo -e "write (13,5) -1471\r"; sleep 2;
echo -e "write (13,6) -1389\r"; sleep 2;
echo -e "write (13,9) -1591\r"; sleep 2;
echo -e "write (13,10) -1521\r"; sleep 2;
echo -e "write (13,11) -1502\r"; sleep 2;
echo -e "write (13,12) -1483\r"; sleep 2;
echo -e "write (13,13) -1585\r"; sleep 2;
echo -e "write (13,14) -1560\r"; sleep 2;
echo -e "write (14,0) -1407\r"; sleep 2;
echo -e "write (14,1) -1484\r"; sleep 2;
echo -e "write (14,2) -1520\r"; sleep 2;
echo -e "write (14,3) -1469\r"; sleep 2;
echo -e "write (14,4) -1376\r"; sleep 2;
echo -e "write (14,5) -1417\r"; sleep 2;
echo -e "write (14,6) -1340\r"; sleep 2;
echo -e "write (14,9) -1158\r"; sleep 2;
echo -e "write (14,10) -1234\r"; sleep 2;
echo -e "write (14,11) -1449\r"; sleep 2;
echo -e "write (14,12) -1279\r"; sleep 2;
echo -e "write (14,13) -1296\r"; sleep 2;
echo -e "write (14,14) -1501\r"; sleep 2;
echo -e "write (15,0) -1431\r"; sleep 2;
echo -e "write (15,1) -1194\r"; sleep 2;
echo -e "write (15,2) -1001\r"; sleep 2;

sleep 2;
echo -e "read (0-15,0-15)\r";
sleep 10;
echo -e "\r";
echo -e "\r";
echo -e "^]";
sleep 1;
) | telnet fms-serv.trg.bnl.local 7006 > ../hvlog_run11/fms_hv2_7006_$t.tex
echo Set new HV
cat ../hvlog_run11/fms_hv2_7006_$t.tex
