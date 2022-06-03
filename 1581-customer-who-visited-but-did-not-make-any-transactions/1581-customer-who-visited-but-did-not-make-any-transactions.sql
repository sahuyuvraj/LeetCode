# Write your MySQL query statement below
SELECT customer_id,COUNT(*) as count_no_trans
FROM Visits v LEFT JOIN Transactions t ON(v.visit_id=t.visit_id)
WHERE transaction_id IS NULL Group By customer_id;
