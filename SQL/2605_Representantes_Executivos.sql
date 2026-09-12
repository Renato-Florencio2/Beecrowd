-- https://judge.beecrowd.com/pt/problems/view/2605

select prod.name, prov.name
from products as prod
inner join providers as prov 
    on prod.id_providers = prov.id
where prod.id_categories = 6;
