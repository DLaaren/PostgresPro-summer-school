# PostgresPro-summer-school

Транзакции -- либо операция выполняется полностью, либо не выполняется вообще

Св-ва транзакции:
1) Атомарность (все или ничего)
2) Согласованность (ограничения целостности и ограничения пользователя)
3) Изоляция (влияние параллельных процессов)
4) Долговечность (сохранность после сбоя)

![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/79371a1d-847f-4f41-b865-0efcdaa365d9)

Внутри одной транзакции можно ставить savepoint'ы -- точки отката. Они живут только в пределах жизни одной транзакции и после затираются. 
Откат к точке сохранения не подразумевает передачу управления (как GOTO) - отменяются только изменения состояния БД.

Вместо того чтобы сразу выполнять весь запрос, есть возможность настроить курсор, инкапсулирующий запрос, и затем получать результат запроса по нескольку строк за раз. Одна из причин так делать заключается в том, чтобы избежать переполнения памяти, когда результат содержит большое количество строк.

 ХРАНЕНИЕ ДАННЫХ
 ![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/17eff5cb-dab6-4adf-a443-6868f41b06f7)

 ИТОГИ
 
 ![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/c14403c8-00e2-4481-ab6e-d54247338971)


::Our team decided to choose project about proxy::

HOOKS IN POSTGRESQL
https://github.com/taminomara/psql-hooks
https://supabase.com/blog/roles-postgres-hooks

Each hook is a pointer to a function, initially set to be NULL.
During its work, postgres checks whether certain function pointers are not null and if that's the case, calls them



