# Write your MySQL query statement below

select customer_id, COUNT(customer_id) as count_no_trans
from Visits v left join Transactions as t
on v.visit_id = t.visit_id
where transaction_id is NULL
group by customer_id;

