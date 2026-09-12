-- https://judge.beecrowd.com/pt/problems/view/2619

select prod.name, prov.name, prod.price
from products as prod
inner join providers as prov
    on prod.id_providers = prov.id
inner join categories as c
    on prod.id_categories = c.id
where prod.price > 1000 and c.name = 'Super Luxury';
