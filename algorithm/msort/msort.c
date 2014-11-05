/*****************************************
*	
*	20093267 ��ǻ�Ͱ��к� 3�г� �輺��
*
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ~ Byte-wise swap two items of size SIZE.
// ~ Byte ���� swap ����
#define SWAP(a, b, size) \
do{ \
	register size_t __size = (size); \
	register char *__a = (a), *__b = (b); \
	do{ \
		char __tmp = *__a; \
		*__a++ = *__b; \
		*__b++ = __tmp; \
	} while (--__size > 0); \
} while (0)

// ~ �Է� ���� x,y �� �� �� ���� �� ����
#define msort_min(x, y) ((x) < (y) ? (x) : (y))
	
#define MAX_SIZE 101

// ~ Discontinue quicksort algorithm when partition gets below this size.
// ~ Quick sort �� �����ϰ� size �� 4������ ��쿡�� Merge Sort ���� �ʵ��� ��
#define MAX_THRESH 4

/**
*	@param base
*		type void * : ���ĵ� �ڷᰡ ����� 1���� �迭�� ���� �ּ�
*	@param total_elems
*		type size_t : �迭�� ����� �ڷ��� ����
*	@param size
*		type size_t : �迭�� ����� �� ���� �ڷᰡ �����ϴ� �޸��� ũ�� (����Ʈ ��)
*	@param int (*compare)(const void *, const void *)
*		type int fn : �迭�� ����� �� ���� �ڷ��� ũ�⸦ ���ϴ� �Լ� ������
*/
void msort (void *base, size_t total_elems, size_t size, int (*cmp)(const void *, const void *)){

	register char *base_ptr = (char *) base;
	register char *insert_ptr = (char *) base;
	const size_t max_thresh = MAX_THRESH * size;
	
	char *left_ptr;
	char *right_ptr;

	char *temp_buffer = (char *) malloc(size * total_elems);


	size_t block, start, mid, end;
	size_t i, j, m;

	// ~ �迭�� ����� �ڷ��� ������ 0�� ���� ������ ���� �������� �ٷ� �����Ѵ�.
	if(total_elems == 0)
		return;

	// ~ MAX_TRHESH 4�εΰ� 4���� ���� ���տ� ���ؼ��� Insertion sort�� �����ϰ� �Ѵ�.
	for (i = 0; i < (total_elems / MAX_THRESH + 1); i++ ){
		char *const end_ptr = base_ptr + (((i + 1) *  MAX_THRESH - 1) * size);
		char *tmp_ptr = base_ptr + (i * MAX_THRESH * size);
		char *thresh = msort_min(end_ptr, base_ptr + (size * (total_elems-1)));
		register char *run_ptr;
		insert_ptr = base_ptr + (i * MAX_THRESH * size);

		/* Find smallest element in first threshold and place it at the
			array's beginning.  This is the smallest array element,
			and the operation speeds up insertion sort's inner loop. */
		// ~ Threshold���� ���� �κ��� �����ؼ� �����Ѵ�.
		for (run_ptr = tmp_ptr + size; run_ptr <= thresh; run_ptr += size)
			if ((*cmp) ((void *) run_ptr, (void *) tmp_ptr) < 0)
				tmp_ptr = run_ptr;

		if (tmp_ptr != insert_ptr)
			SWAP (tmp_ptr, insert_ptr, size);

		// ~ Insertion sort, running from left-hand-side up to right-hand-side.
		// ~ Insertion sorting ���� ���ʿ��� ���� ����������
		run_ptr = insert_ptr + size;
		while ((run_ptr += size) <= thresh){
			tmp_ptr = run_ptr - size;
			while ((*cmp) ((void *) run_ptr, (void *) tmp_ptr) < 0)
				tmp_ptr -= size;
			
			tmp_ptr += size;
			if (tmp_ptr != run_ptr){
				char *trav;
				trav = run_ptr + size;
				
				while (--trav >= run_ptr){
					char c = *trav;
					char *hi, *lo;

					for (hi = lo = trav; (lo -= size) >= tmp_ptr; hi = lo)
						*hi = *lo;
					*hi = c;
				}
			}
		}
	}

	// ~ Divide
	for (block = 4; block < total_elems; block *= 2 ) {       
		// ~ left_ptr�� ���� ���� �ʱ�ȭ
		left_ptr = base_ptr;
		for (start = 0; start + block < total_elems; start += (block * 2), left_ptr = right_ptr ) {
			// ~ right_ptr�� ���� ��ġ ���� 
			right_ptr = left_ptr + (block * size);
            
			// ~ �߰� ��ġ�� �� ��ġ ���� Merge ��ų �ΰ��� divide���� ����
			mid = start + block;
			end = mid + block;
			if (end > total_elems){  
				end = total_elems;
			}

            m = start, i = start, j = mid; 

			// ~ Merge ���� Combine
            while (i < mid && j < end) { 
                if ((*cmp) ((void *) left_ptr, (void *) right_ptr) < 0) {         
					memcpy(temp_buffer + (m*size), left_ptr, size);
					i++, left_ptr += (1*size);
                } else {
					memcpy(temp_buffer + (m*size), right_ptr, size);
					j++, right_ptr += (1*size);
                }
                m++;
            }
			
            if (i < mid) { 
				memcpy(temp_buffer + (m * size), left_ptr, (mid - i) * size);
				left_ptr += (mid- i) * size;
            }

            if (j < end) { 
				memcpy(temp_buffer + (m * size), right_ptr, (end - j) * size );
				right_ptr += (end - j) * size;
            }

			memcpy(base_ptr + (start * size), temp_buffer + (start * size), size * (end - start));
        }
    }

	free(temp_buffer);
}

int icompare(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(void){
	FILE *in;
	int numTestCase;
	int arrSort[MAX_SIZE] = { 0, };
	int sizeSort, temp, i;
	
	in = fopen("input.txt", "r");
	fscanf(in, "%d", &numTestCase);
	
	while(numTestCase--){
		fscanf(in, "%d", &sizeSort);
		
		for(i=0; i<sizeSort; i++){
			fscanf(in, "%d", &temp);
			arrSort[i] = temp;
		}

		//qsort(arrSort, sizeSort, sizeof(int), icompare); 
		msort(arrSort, sizeSort, sizeof(int), icompare);
		
		for (i=0; i<sizeSort; i++){
			printf("%d ", arrSort[i]);
		} 
		printf("\n");
	}

	return 0;
}