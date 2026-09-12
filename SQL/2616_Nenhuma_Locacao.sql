-- https://judge.beecrowd.com/pt/problems/view/2616

select c.id, c.name
from customers as c
left join locations as l
    on l.id_customers = c.id
group by c.id
having count(l.id_customers) = 0
order by c.id ASC;
