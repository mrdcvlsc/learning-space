## Installing PostgreSQL

To manually configure the Apt repository, follow these steps:

```bash
# Import the repository signing key:
sudo apt install curl ca-certificates
sudo install -d /usr/share/postgresql-common/pgdg
sudo curl -o /usr/share/postgresql-common/pgdg/apt.postgresql.org.asc --fail https://www.postgresql.org/media/keys/ACCC4CF8.asc

# Create the repository configuration file:
sudo sh -c 'echo "deb [signed-by=/usr/share/postgresql-common/pgdg/apt.postgresql.org.asc] https://apt.postgresql.org/pub/repos/apt $(lsb_release -cs)-pgdg main" > /etc/apt/sources.list.d/pgdg.list'

# Update the package lists:
sudo apt update

# Install the latest version of PostgreSQL:
# If you want a specific version, use 'postgresql-16' or similar instead of 'postgresql'
sudo apt -y install postgresql
```

## Creating and Deleteing Roles/Users From PostgreSQL promt

```bash
# login to the default postgres user environment
sudo -i -u postgres

# =============== default postgres user environment starts here ==============

# access postgres promt
psql

# ======================== postgres promt starts here ========================

# list all current roles (inside postgres promt)
\du

# create new role (inside postgres promt)
CREATE ROLE <new_role_name>;

# delete a role (inside postgres promt)
DROP ROLE <role_name>;
# or
DROP ROLE IF EXISTS role_name;

# exit postgres promt
exit

# ======================== postgres promt ends here ==========================

# exitpostgres server
exit

# =============== default postgres user environment ends here ================
```

## Adding Role Permissions Upon Role Creation

```bash
Description: define a new database role
Syntax:
CREATE ROLE name [ [ WITH ] option [ ... ] ]

where option can be:

      SUPERUSER | NOSUPERUSER
    | CREATEDB | NOCREATEDB
    | CREATEROLE | NOCREATEROLE
    | INHERIT | NOINHERIT
    | LOGIN | NOLOGIN
    | REPLICATION | NOREPLICATION
    | BYPASSRLS | NOBYPASSRLS
    | CONNECTION LIMIT connlimit
    | [ ENCRYPTED ] PASSWORD 'password' | PASSWORD NULL
    | VALID UNTIL 'timestamp'
    | IN ROLE role_name [, ...]
    | IN GROUP role_name [, ...]
    | ROLE role_name [, ...]
    | ADMIN role_name [, ...]
    | USER role_name [, ...]
    | SYSID uid

# example:
CREATE ROLE semiadmin WITH NOSUPERUSER CREATEDB CREATEROLE LOGIN ENCRYPTED PASSWORD 'testpassword';
```

## Create Roles from command line

```bash
# login to the default postgres user environment
sudo -i -u postgres

# =============== default postgres user environment starts here ==============

# access postgres promt
psql

# ======================== postgres promt starts here ========================

# list all current roles (inside postgres promt)
\du

# create new role with permission yes or no question promts
createuser --interactive

# answer the questions with y or n ...

# exit postgres promt
exit

# ======================== postgres promt ends here ==========================

# exitpostgres server
exit

# =============== default postgres user environment ends here ================

```

## Edit Role Premissions

```bash
# see different options above similar in role creation
ALTER ROLE <role_name> [ WITH ] option [ ... ]
```
## Add password to a role

```bash
\password test_user
```

## Grant or Revoke Table Permission to Roles

```bash
# grant permissions
GRANT <permission_type> ON <table_name> TO <role_name>;

# revoke permissions
REVOKE <permission_type> ON <table_name> FROM <user_name>;

# use command below to see different permission types
# \h GRANT
```




### REFERENCES

- https://www.postgresql.org/download/linux/ubuntu/
- https://www.digitalocean.com/community/tutorials/how-to-use-roles-and-manage-grant-permissions-in-postgresql-on-a-vps-2
