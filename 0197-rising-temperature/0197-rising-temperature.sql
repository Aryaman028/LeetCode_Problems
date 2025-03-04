# Write your MySQL query statement 
-- AS WE HAVE TO COMPARE IN THE TABLE ITSELF THEN WE WOULD DO THE SELF JOIN

SELECT a.id
FROM Weather as a
join Weather as b    
on DATEDIFF(a.recordDate,b.recordDate) = 1 
where a.temperature > b.temperature;