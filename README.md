# PostgresPro-summer-school

::HOW TO INSTALL POSTGRESQL FROM SOURCE CODE::

1) git clone --branch <branch_name> https://github.com/postgres/postgres
2) go to just cloned dir and execute ./configure
3) make (or make all) (or make world if you want eveeeerryyythiing)
4) (optional) make check (just tests)
5) make install
6) useradd postgres && passwd < password >
7) create dir for our future db cluster : mkdir -p /var/lib/postgres
8) change owner of this dir : chown -R postgres:postgres /var/lib/postgres
9) su - postgres
10) initialize db : initdb -D /var/lib/postgres/data <bd_name>
    !!attention!!
    if there is "command not found", try : find / -name <command_name>
    then use the full path to the command (or create link)
11) pg_ctl -D /var/lib/postgres/data start
12) psql -h 127.0.0.1 -p 5432 -d <db_name> -U <user_name>

(I spent 2 days and all my nerves on this)
