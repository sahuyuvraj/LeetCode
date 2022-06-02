# Write your MySQL query statement below
SELECT employee_id
FROM (SELECT employee_id FROM employees 
      UNION 
      SELECT employee_id FROM salaries) t
WHERE employee_id NOT IN (
    SELECT employee_id FROM employees 
    JOIN salaries USING (employee_id))
ORDER BY employee_id