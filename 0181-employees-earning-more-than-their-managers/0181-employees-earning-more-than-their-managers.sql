# Write your MySQL query statement below


SELECT 
    e.name  as Employee
FROM   
    Employee m LEFT JOIN Employee e ON m.Id = e.managerId
WHERE 
    m.salary < e.salary;

