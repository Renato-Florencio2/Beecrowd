-- https://judge.beecrowd.com/pt/problems/view/2617

select prod.name, prov.name
from providers as prov
inner join products as prod
    on prod.id_providers = prov.id
where prov.name = 'Ajax SA';
