# PostgresPro-summer-school

(every bench is every day)

![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/fc25a732-9e33-41e1-91a0-d14cd388fee3)

Если каждый раз записывать все изменения состояния БД на диск -- очееень долго и невыгодно ---> поэтому пользуемся журналированием

В лог не попадают записи с временными таблицами + нежурналируемые страницы

![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/1129ae50-6933-439a-aa8a-c98cca7ae3d6)


![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/a0bae207-91b8-4fdc-bb48-4fa59162eeff)

Синхронная запись в WAL -- сразу после выполнения транзакции ( -- если долгая операция, то запись в журнал блокируется)

Асинхронная -- фоновым процессом


![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/49d5c124-7ef2-43ff-82fd-d664fb1257b6)


Утилита pg_waldump


![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/6a257e5a-c3d1-49a8-81d8-c8c0109d311f)
![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/6906121e-4ce8-4c98-b43d-5a06daef20f0)

![image](https://github.com/DLaaren/PostgresPro-summer-school/assets/100743455/0cfd37e1-2caf-41d2-a682-736c21456da8)

