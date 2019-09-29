typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <malloc.h>

struct list
{
	int db_idx, prv, nxt;
} lst[250010];
struct trie
{
	int list_idx[5], link[38];
} root, tries[1000010];
struct database
{
	bool isUsed;
	char data[5][20];
	int link[5];
} db[50010];

int list_cnt, trie_cnt, db_cnt, enc[128], enc_cnt;

void InitDB()
{
	int i;
	for (i = 1; i <= 50000; ++i)
	{
		db[i].isUsed = false;
	}
	for (i = 0; i < 128; ++i)
	{
		if (root.link[i])
		{
			root.link[i] = 0;
		}
	}
	list_cnt = 0;
	trie_cnt = 0;
	db_cnt = 0;
	enc_cnt = 0;
	enc['@'] = enc_cnt++;
	enc['.'] = enc_cnt++;
	for (i = '0'; i <= '9'; ++i)
	{
		enc[i] = enc_cnt++;
	}
	for (i = 'a'; i <= 'z'; ++i)
	{
		enc[i] = enc_cnt++;
	}
}

int kstrlen(char *name)
{
	int i = 0;
	while (*(name++))
	{
		i++;
	}
	return i;
}

void swap(char *a, char *b)
{
	char t;
	t = *a;
	*a = *b;
	*b = t;
}

void reverse(char *a)
{
	int i, len = kstrlen(a);
	for (i = 0; i < len / 2; ++i)
	{
		swap(&a[i], &a[len - i - 1]);
	}
}

void kstrcpy(char *dst, char *src)
{
	int i, len = kstrlen(src);
	for (i = 0; i <= len; ++i)
	{
		dst[i] = src[i];
	}
}

void Add(char *name, char *number, char *birthday, char *email, char *memo)
{
	int i, j, k, len, db_idx;
	char *strs[5] = {
		name,
		number,
		birthday,
		email,
		memo};
	trie *now;
	if (db_cnt < 50000)
	{
		db_idx = ++db_cnt;
	}
	else
		for (db_idx = 1; db_idx <= 50000; ++db_idx)
		{
			if (!db[db_idx].isUsed)
			{
				break;
			}
		}
	db[db_idx].isUsed = true;
	for (i = 0; i < 5; ++i)
	{
		kstrcpy(db[db_idx].data[i], strs[i]);
	}
	reverse(email);
	for (i = 0; i < 5; ++i)
	{
		len = kstrlen(strs[i]);
		now = &root;
		for (j = 0; j < len; ++j)
		{
			if (!now - > link[enc[strs[i][j]]])
			{
				now - > link[enc[strs[i][j]]] = ++trie_cnt;
				for (k = 0; k < 5; ++k)
				{
					tries[trie_cnt].list_idx[k] = 0;
				}
				for (k = 0; k < 128; ++k)
				{
					tries[trie_cnt].link[k] = 0;
				}
			}
			now = &tries[now - > link[enc[strs[i][j]]]];
		}
		lst[++list_cnt].db_idx = db_idx;
		lst[list_cnt].prv = 0;
		lst[list_cnt].nxt = now - > list_idx[i];
		if (now - > list_idx[i])
		{
			lst[now - > list_idx[i]].prv = list_cnt;
		}
		now - > list_idx[i] = list_cnt;
		db[db_idx].link[i] = now - tries;
	}
}

int Delete(FIELD field, char *str)
{
	int i, len = kstrlen(str), list_idx, del_idx, prv, nxt, step, ret = 0;
	trie *now = &root;
	if (field == EMAIL)
		reverse(str);
	for (i = 0; i < len; ++i)
	{
		now = &tries[now - > link[enc[str[i]]]];
		if (now == NULL)
			return 0;
	}
	list_idx = now - > list_idx[field];
	while (list_idx)
	{
		ret++;
		step = lst[list_idx].nxt;
		for (i = 0; i < 5; ++i)
		{
			del_idx = tries[db[lst[list_idx].db_idx].link[i]].list_idx[i];
			if (lst[del_idx].db_idx == lst[list_idx].db_idx)
			{
				tries[db[lst[list_idx].db_idx].link[i]].list_idx[i] = lst[del_idx].nxt;
			}
			while (lst[del_idx].db_idx != lst[list_idx].db_idx)
			{
				del_idx = lst[del_idx].nxt;
			}
			prv = lst[del_idx].prv;
			nxt = lst[del_idx].nxt;
			if (prv)
				lst[lst[del_idx].prv].nxt = nxt;
			if (nxt)
				lst[lst[del_idx].nxt].prv = prv;
		}
		db[lst[list_idx].db_idx].isUsed = false;
		list_idx = step;
	}
	return ret;
}
int Change(FIELD field, char *str, FIELD changefield, char *changestr)
{
	int i, j, len = kstrlen(str), list_idx, mov_idx, prv, nxt, step, ret = 0;
	trie *now = &root, *chg = &root;
	char original[20];
	kstrcpy(original, changestr);
	if (field == EMAIL)
		reverse(str);
	if (changefield == EMAIL)
		reverse(changestr);
	for (i = 0; i < len; ++i)
	{
		now = &tries[now - > link[enc[str[i]]]];
		if (now == NULL)
			return 0;
	}
	len = kstrlen(changestr);
	for (i = 0; i < len; ++i)
	{
		if (!chg - > link[enc[changestr[i]]])
		{
			chg - > link[enc[changestr[i]]] = ++trie_cnt;
			for (j = 0; j < 5; ++j)
				tries[trie_cnt].list_idx[j] = 0;
			for (j = 0; j < 128; ++j)
				tries[trie_cnt].link[j] = 0;
		}
		chg = &tries[chg - > link[enc[changestr[i]]]];
	}
	list_idx = now - > list_idx[field];
	if (list_idx == 0)
		return 0;
	while (list_idx)
	{
		ret++;
		step = lst[list_idx].nxt;
		mov_idx = tries[db[lst[list_idx].db_idx].link[changefield]].list_idx[changefield];
		if (lst[mov_idx].db_idx == lst[list_idx].db_idx)
			tries[db[lst[list_idx].db_idx].link[changefield]].list_idx[changefield] = lst[mov_idx].nxt;
		while (lst[mov_idx].db_idx != lst[list_idx].db_idx)
			mov_idx = lst[mov_idx].nxt;
		prv = lst[mov_idx].prv;
		nxt = lst[mov_idx].nxt;
		if (prv)
			lst[lst[mov_idx].prv].nxt = nxt;
		if (nxt)
			lst[lst[mov_idx].nxt].prv = prv;
		lst[mov_idx].prv = 0;
		lst[mov_idx].nxt = chg - > list_idx[changefield];
		if (chg - > list_idx[changefield])
			lst[chg - > list_idx[changefield]].prv = mov_idx;
		chg - > list_idx[changefield] = mov_idx;
		db[lst[list_idx].db_idx].link[changefield] = chg - tries;
		kstrcpy(db[lst[list_idx].db_idx].data[changefield], original);
		list_idx = step;
	}
	now - > list_idx[changefield] = 0;
	return ret;
}
RESULT Search(FIELD field, char *str, FIELD ret_field)
{
	int i, len = kstrlen(str), list_idx;
	trie *now = &root;
	RESULT result = {
		0};
	if (field == EMAIL)
		reverse(str);
	for (i = 0; i < len; ++i)
	{
		now = &tries[now - > link[enc[str[i]]]];
		if (now == NULL)
			return result;
	}
	list_idx = now - > list_idx[field];
	while (list_idx)
	{
		result.count++;
		kstrcpy(result.str, db[lst[list_idx].db_idx].data[ret_field]);
		list_idx = lst[list_idx].nxt;
	}
	return result;
}