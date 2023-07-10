# PostgresPro-summer-school

start : postgres -D data -c shared_preload_libraries=my_bgw

TODO: add a dymanic bgw (I'm too lazy)

Difference between BGW and Dynamic BGW :
  BGW is started by the main process (postgres aka postmaster), and BGW starts working just after launch
  Dynamic BGW is started by backend (you need to write "create extension Dynamic BGW;")

(every bench is every day)
