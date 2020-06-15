-- joins

2 tables

SELECT outerTable.unique1
FROM   cs587_benchmark1.tenktup1 AS outerTable
  INNER JOIN cs587_benchmark1.tenktup2 AS innerTable
    ON outerTable.unique1 = innerTable.unique2;

-----------------------------------------------------------------

SELECT outerTable.unique1,
	( SELECT count(*)
	  FROM cs587_benchmark1.tenktup2 AS innerTable
	  WHERE outerTable.unique1 = innerTable.unique2
	)
FROM cs587_benchmark1.tenktup1 AS outerTable;

-----------------------------------------------------------------

3 tables

SELECT first.unique1
FROM cs587_benchmark1.onektup AS first
  INNER JOIN cs587_benchmark1.tenktup1 AS second
	ON first.unique1 = second.unique2
  INNER JOIN cs587_benchmark1.tenktup2 AS third
   	ON second.unique1 = third.unique2;

-----------------------------------------------------------------

--insert query w/o index

INSERT INTO cs587_benchmark1.testTable1
SELECT *
FROM cs587_benchmark1.tenktup1
WHERE unique2 > 10000;

-----------------------------------------------------------------

--insert query w/ index


CREATE INDEX idx_tentkup1
ON cs587_benchmark1.tenktup1 (unique1, unique2);

INSERT INTO cs587_benchmark1.testTable2
SELECT *
FROM cs587_benchmark1.tenktup1
WHERE unique2 > 10000;


---------------------------------------------------------

--aggregate query w/o index

SELECT fiftypercent, COUNT(fiftypercent)
FROM cs587_benchmark1.tenktup2
GROUP BY fiftypercent;

-----------------------------------------------------------------

--aggregate query w/index

CREATE INDEX cs587_benchmark1.idx_tentkup2
ON cs587_benchmark1.tenktup2 (fiftypercent);

SELECT fiftypercent, COUNT(fiftypercent)
FROM cs587_benchmark1.tenktup2
GROUP BY fiftypercent;





