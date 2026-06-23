# Write your MySQL query statement below
SELECT product_name, year, price
FROM Sales as s
JOIN Product as pd
ON s.product_id = pd.product_id;