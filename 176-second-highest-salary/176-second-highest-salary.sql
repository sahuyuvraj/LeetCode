# Write your MySQL query statement below
#SELECT MAX(salary) as SecondHighestSalary FROM Employee WHERE salary <>(SELECT MAX(salary) FROM Employee);
SELECT MAX(salary) AS SecondHighestSalary 
FROM Employee 
WHERE salary <> (
    SELECT salary 
    FROM Employee 
    GROUP BY salary 
    ORDER BY salary 
    DESC LIMIT 1);