# Write your MySQL query statement below

SELECT DISTINCT(t1.id) AS id,
CASE
    WHEN t1.p_id IS NULL THEN 'Root'
    WHEN t2.id IS NULL THEN 'Leaf'
    ELSE 'Inner'
END AS type
FROM Tree as t1 LEFT JOIN Tree as t2 ON t1.id=t2.p_id;

# SELECT id,'Root' AS type FROM Tree WHERE
# p_id IS NULL
# UNION

# SELECT id,'Inner' AS type FROM Tree WHERE 
# id IN(SELECT p_id FROM Tree)
# AND p_id IS NOT NULL
# UNION

# SELECT id,'Leaf' AS type FROM Tree WHERE
# id NOT IN(SELECT p_id FROM Tree WHERE p_id IS NOT NULL)
# AND p_id IS NOT NUll;
