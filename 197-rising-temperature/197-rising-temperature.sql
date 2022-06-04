# Write your MySQL query statement below

#self join

SELECT a.id 
FROM Weather a,Weather b 
WHERE a.recordDate=b.recordDate+INTERVAL 1 DAY
AND a.temperature>b.temperature;