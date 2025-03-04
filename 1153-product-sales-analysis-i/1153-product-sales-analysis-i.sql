# Write your MySQL query statement below
SELECT
    PRODUCT_NAME, YEAR, PRICE
FROM
    Product inner join Sales
    on Product.product_id = Sales.product_id;
