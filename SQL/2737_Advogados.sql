-- https://judge.beecrowd.com/pt/problems/view/2737

(
    select l.name, l.customers_number
    from lawyers as l
    order by l.customers_number DESC
    limit 1
)

union all

(
    select l.name, l.customers_number
    from lawyers as l
    order by l.customers_number ASC
    limit 1
)

union all

(
    select 'Average', round ( avg(l.customers_number) )
    from lawyers as l
);
