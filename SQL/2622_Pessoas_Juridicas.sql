-- https://judge.beecrowd.com/pt/problems/view/2622

select c.name
from legal_person as l
inner join customers as c
    on l.id_customers = c.id;
