# Experiments in extending PG

### Build

1. Compile C code.

```
cc -fPIC -isystem `pg_config --includedir-server` -c point3d.c
```

2. Make shared object

```
cc -shared -o point3d.so point3d.o
```

3. Copy into pg library folder

```
cp point3d.so `pg_config --pkglibdir`
```
