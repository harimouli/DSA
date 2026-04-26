# Write your MySQL query statement below


SELECT 
    Department , 
    Employee, 
    salary 
FROM (
    SELECT
        d.name AS Department, 
        e.name AS Employee, 
        e.salary AS salary, 

        DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS rnk
    FROM 
        Employee AS e 

    INNER JOIN  Department AS d 
    ON  e.departmentId = d.id ) t 

WHERE 
    rnk <= 3

ORDER BY 
    Department , salary DESC, Employee;

