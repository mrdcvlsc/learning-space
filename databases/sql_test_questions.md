# SQL Practice — Questions Only

This file contains practice questions based on the sql_guide.md file. Answer style: mix of short explanations (sentence form), single-word/keyword fill-in-the-blank, and one-line SQL or commands.

---

1. **Database creation:** In one sentence, explain the difference between creating a database on MySQL/MariaDB and creating/opening a database in SQLite.

2. **Charset recommendation:** Fill in the blank (one keyword): The recommended character set for full Unicode support in MySQL/MariaDB is `_____`.

3. **Create database SQL:** Write the single-line SQL command to create a database named `app_db` with `utf8mb4` and `utf8mb4_unicode_ci` collation (MySQL syntax).

4. **SQLite attach:** Provide the one-line SQLite command to attach a file `other.db` under the alias `other_db`.

5. **Permissions:** In one or two sentences, describe why application accounts should have limited privileges rather than global privileges.

6. **Storage engines:** Briefly explain, in a sentence, the main practical difference between InnoDB and MyISAM and which one you should prefer for modern apps.

7. **USE statement:** Provide the one-line SQL command used on server engines to set the current database to `app_db`.

8. **Cross-database queries:** In a sentence, explain how to reference a table in another database/schema on server engines.

9. **Drop database caution:** Give two concise safety steps you should perform before running `DROP DATABASE` on a production server.

10. **Minimal table creation:** Write a short SQL snippet (one `CREATE TABLE` statement) that creates a minimal `items` table with an integer primary key and a NOT NULL `name` column, compatible with both SQLite and MySQL.

11. **SQLite special PK:** One sentence: what is special about `INTEGER PRIMARY KEY` in SQLite?

12. **Autoincrement differences:** In one sentence, contrast `AUTO_INCREMENT` behavior in MySQL with the `AUTOINCREMENT` keyword in SQLite.

13. **Adding a column:** Provide the one-line `ALTER TABLE` command to add a `created_at` DATETIME column defaulting to the current timestamp to the `items` table.

14. **ALTER pitfalls:** In one or two sentences, explain why adding a `NOT NULL` column without a default may fail on a populated table.

15. **Renaming table and column:** Give the two one-line SQL statements to rename table `items` to `products` and then rename column `name` to `title` on supported engines.

16. **Dropping columns:** In a sentence, explain why dropping columns can be risky and what safer migration pattern the cheat-sheet recommends.

17. **Primary vs unique:** One sentence: what does a `PRIMARY KEY` imply that a `UNIQUE` constraint does not explicitly require?

18. **Foreign keys in SQLite:** Fill in the blank: To enforce foreign keys in SQLite per connection you must run `PRAGMA foreign_keys = _____;` (answer `ON` or `OFF`).

19. **Index creation:** Provide a one-line SQL command to create a non-unique index on `users(username)` named `idx_users_username`.

20. **Index pitfalls:** In two short sentences, explain why `LIKE '%term%'` is slow and when indexes are not used.

21. **SELECT * pitfall:** In one sentence, explain a problem of using `SELECT *` in production code related to schema evolution.

22. **Projection:** Write the one-line SQL to select only `id`, `username`, and `email` from `users`.

23. **WHERE NULL checks:** In one sentence, state how you check for NULL values in SQL.

24. **ORDER BY determinism:** Give a short SQL example (two columns in `ORDER BY`) that produces deterministic ordering using `created_at` and `id` descending.

25. **Pagination (limit/offset):** Write a simple one-line SQL that returns the first page of 10 users ordered by `created_at` descending.

26. **Keyset pagination:** In one or two sentences, explain why keyset pagination is preferred over large offsets.

27. **LIKE wildcard meaning:** Fill in the blanks: In `LIKE` patterns, `%` matches _____ and `_` matches _____ (one-word answers each).

28. **INNER vs LEFT JOIN:** In one sentence each, state the difference between `INNER JOIN` and `LEFT JOIN`.

29. **Detect missing relations:** Provide the one-line SQL pattern (conceptual) that uses `LEFT JOIN` to find rows in `users` with no corresponding `posts`.

30. **Aggregation basics:** Write the one-line SQL that counts users grouped by the `active` flag and names the count column `cnt`.

31. **ONLY_FULL_GROUP_BY:** In one sentence, explain what `ONLY_FULL_GROUP_BY` enforces in MySQL.

32. **Insert single row:** Provide a one-line `INSERT` statement to add user `erin` with email `e@example.com` and active `1` into `users` (column list included).

33. **Retrieve last id:** In one sentence, name the function to get the last inserted id in SQLite and MySQL respectively.

34. **Batch insert:** Provide a one-line SQL inserting two rows into `users` (`frank` and `gina`) with their emails and active flags as shown in the cheat-sheet.

35. **Update caution:** One sentence: what happens if you run `UPDATE users SET last_login = CURRENT_TIMESTAMP;` without a `WHERE` clause?

36. **Delete vs soft-delete:** In two sentences, explain the difference between a hard delete and a soft delete and why you might prefer soft deletes.

37. **Upsert MySQL:** Provide the one-line MySQL `INSERT ... ON DUPLICATE KEY UPDATE` statement shown in the cheat-sheet for key `site_hits`.

38. **Transaction basics:** Write the minimal SQL sequence (BEGIN/COMMIT) to transfer 100 from account 1 to account 2 using two `UPDATE` statements as in the cheat-sheet.

39. **Isolation levels:** List three isolation levels mentioned in the cheat-sheet that MySQL/MariaDB support.

40. **WAL in SQLite:** In one sentence, explain why turning on `PRAGMA journal_mode = WAL;` can improve concurrency in SQLite and one caveat to be aware of.

41. **When to index:** In two short sentences, explain when you should add an index and one case where you should avoid indexing.

42. **Composite index left-most rule:** In one sentence, state the left-most prefix rule for composite indexes.

43. **EXPLAIN usage:** Provide the one-line SQL to explain the query `SELECT * FROM users WHERE email = 'a@example.com';` on MySQL, and the equivalent for SQLite.

44. **Full-text vs LIKE:** In one sentence, explain the advantage of full-text search over `LIKE` for large text columns.

45. **Backup strategies:** List three essential elements of a good backup strategy mentioned in the cheat-sheet (short bullet-style answer acceptable).

46. **SQLite VACUUM:** One sentence: what does `VACUUM;` do in SQLite and what is a maintenance consideration when running it?

47. **Show schema:** Provide the one-line MySQL command to show table creation SQL for `users`, and the SQLite query to get the `sql` from `sqlite_master` for `users`.

48. **Show indexes:** Provide the single-line commands to list indexes for `users` in MySQL and in SQLite.

49. **Practical troubleshooting:** In two sentences, explain why running `ANALYZE TABLE` or `ANALYZE` can help query performance.

50. **Extra credit (short SQL):** Write a one-line SQL using `GROUP BY` and `HAVING` to find usernames that appear more than once in `users` (assume `username` may not be unique).