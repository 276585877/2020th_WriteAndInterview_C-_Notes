/*
// �򵥲����㷨��Ҫ������������� input iterator��
find(beg, end, val);				//����һ��������ָ�����������е�һ������ val ��Ԫ�أ�δ�ҵ����� end
find_if(beg, end, unaryPred);		//���ص������� ָ���һ������ unaryPred ��Ԫ�أ�δ�ҵ����� end
find_if_not(beg, end, unaryPred);	// ���ص������� ָ���һ���� unaryPred Ϊ false ��Ԫ�أ�δ�ҵ����� end

count(beg, end, val);				// ����һ����������ָ�� val �����˶��ٴ�
count_if(beg, end, unaryPred);		// ͳ���ж��ٸ�Ԫ������ unaryPred

all_of(beg, end, unaryPred);		// ����һ�� bool ֵ���ж��Ƿ�����Ԫ�ض����� unaryPred
any_of(beg, end, unaryPred);		// ����һ�� bool ֵ���ж��Ƿ����⣨���ڣ�һ��Ԫ������ unaryPred
none_of(beg, end, unaryPred);		// ����һ�� bool ֵ���ж��Ƿ�����Ԫ�ض������� unaryPred

// �����ظ�ֵ���㷨��������ǰ�������� forward iterator��
adjacent_find(beg, end);					// ����ָ���һ�������ظ�Ԫ�صĵ�������������Ԫ���򷵻� end
adjacent_find(beg, end, binaryPred);		// ����ָ���һ�������ظ�Ԫ�صĵ�������������Ԫ���򷵻� end
search_n(beg, end, count, val);				// ���ص������� �Ӵ�λ�ÿ�ʼ�� count �����Ԫ�أ��������򷵻� end
search_n(beg, end, count, val, binaryPred); // ���ص������� �Ӵ�λ�ÿ�ʼ�� count �����Ԫ�أ��������򷵻� end

// �����������㷨���� find_first_of��ǰ���������������������ǰ��������� �⣬��Ҫ������ǰ�������
search(beg1, end1, beg2, end2); // ���صڶ������뷶Χ�������У��ڵ�һ�����뷶Χ�е�һ�γ��ֵ�λ
�ã�δ�ҵ��򷵻� end1
search(beg1, end1, beg2, end2, binaryPred); // ���صڶ������뷶Χ�������У��ڵ�һ�����뷶Χ��
��һ�γ��ֵ�λ�ã�δ�ҵ��򷵻� end1
find_first_of(beg1, end1, beg2, end2); // ���ص������� ָ��ڶ������뷶Χ������Ԫ���ڵ�һ����Χ
���״γ��ֵ�λ�ã�δ�ҵ��򷵻� end1
find_first_of(beg1, end1, beg2, end2, binaryPred); // ���ص������� ָ��ڶ������뷶Χ������
Ԫ���ڵ�һ����Χ���״γ��ֵ�λ�ã�δ�ҵ��򷵻�end1
find_end(beg1, end1, beg2, end2); // ���� search�������ص����һ�γ��ֵ�λ�á�����ڶ������뷶
ΧΪ�գ������ڵ�һ�����뷶ΧΪ�գ������ڵ�һ�����뷶Χ��δ�ҵ������򷵻� end1
find_end(beg1, end1, beg2, end2, binaryPred); // ���� search�������ص����һ�γ��ֵ�λ�á���
���ڶ������뷶ΧΪ�գ������ڵ�һ�����뷶ΧΪ�գ������ڵ�һ�����뷶Χ��δ�ҵ������򷵻� end1
// ����ֻ���㷨���������������
for_each(beg, end, unaryOp); // �����������е�ÿ��Ԫ��Ӧ�ÿɵ��ö��� unaryOp�� unaryOp �ķ���ֵ��
����
mismatch(beg1, end1, beg2); // �Ƚ����������е�Ԫ�ء�����һ���������� pair����ʾ���������е�һ��
��ƥ���Ԫ��
mismatch(beg1, end1, beg2, binaryPred); // �Ƚ����������е�Ԫ�ء�����һ���������� pair����ʾ
���������е�һ����ƥ���Ԫ��
equal(beg1, end1, beg2); // �Ƚ�ÿ��Ԫ�أ�ȷ�����������Ƿ���ȡ�
equal(beg1, end1, beg2, binaryPred); // �Ƚ�ÿ��Ԫ�أ�ȷ�����������Ƿ���ȡ�
// ���������㷨������ǰ���������������ʵ������� random-access iterator����Ҫ�������е�Ԫ���Ѿ�������
�ġ�ͨ��С��������� <���� comp �Ƚϲ���ʵ�ֱȽϡ�
lower_bound(beg, end, val); // ����һ���ǵݼ����� [beg, end) �еĵ�һ�����ڵ���ֵ val ��λ�õĵ�
5 / 7
�������������򷵻� end
lower_bound(beg, end, val, comp); // ����һ���ǵݼ����� [beg, end) �еĵ�һ�����ڵ���ֵ val ��
λ�õĵ��������������򷵻� end
upper_bound(beg, end, val); // ����һ���ǵݼ����� [beg, end) �е�һ������ val ��λ�õĵ���������
�����򷵻� end
upper_bound(beg, end, val, comp); // ����һ���ǵݼ����� [beg, end) �е�һ������ val ��λ�õĵ�
�������������򷵻� end
equal_range(beg, end, val); // ����һ�� pair���� first ��Ա�� lower_bound ���صĵ���������
second ��Ա�� upper_bound ���صĵ�����
binary_search(beg, end, val); // ����һ�� bool ֵ��ָ���������Ƿ�������� val ��Ԫ�ء���������ֵ
x �� y���� x ��С�� y �� y Ҳ��С�� x ʱ����Ϊ������ȡ�
// ֻд�����㷨��Ҫ������������� output iterator��
fill(beg, end, val); // �� val ����ÿ��Ԫ�أ����� void
fill_n(beg, cnt, val); // �� val ���� cnt ��Ԫ�أ�����ָ��д�뵽�����������һ��Ԫ��֮��λ�õĵ�
����
genetate(beg, end, Gen); // ÿ�ε��� Gen() ���ɲ�ͬ��ֵ����ÿ�����У����� void
genetate_n(beg, cnt, Gen); // ÿ�ε��� Gen() ���ɲ�ͬ��ֵ���� cnt �����У�����ָ��д�뵽�������
����һ��Ԫ��֮��λ�õĵ�����
// ʹ�������������д�㷨����ȡһ���������У���ֵд�뵽һ��������У� dest����
copy(beg, end, dest); // �����뷶Χ��Ԫ�ؿ�������Ԫ�ص� dest ָ������Ŀ������
copy_if(beg, end, dest, unaryPred); // �����뷶Χ��Ԫ�ؿ������� unaryPred ��Ԫ�ص� dest ָ����
��Ŀ������
copy_n(beg, n, dest); // �����뷶Χ��Ԫ�ؿ���ǰ n ��Ԫ�ص� dest ָ������Ŀ������
move(beg, end, dest); // �����������е�ÿ��Ԫ�ص��� std::move�������ƶ��������� dest ��ʼʼ������
��
transform(beg, end, dest, unaryOp); // ���ø���������һԪ���������������д�� dest ��
transform(beg, end, beg2, dest, binaryOp); // ���ø�����������Ԫ���������������д�� dest ��
replace_copy(beg, end, dest, old_val, new_val); // ��ÿ��Ԫ�ؿ����� dest�������� old_val ��
��Ԫ���滻Ϊ new_val
replace_copy_if(beg, end, dest, unaryPred, new_val); // ��ÿ��Ԫ�ؿ����� dest��������
unaryPred �ĵ�Ԫ���滻Ϊ new_val
merge(beg1, end1, beg2, end2, dest); // �����������б��붼������ģ��� < ��������ϲ��������
д�뵽 dest ��
merge(beg1, end1, beg2, end2, dest, comp); // �����������б��붼������ģ�ʹ�ø����ıȽϲ���
�� comp�����ϲ��������д�뵽 dest ��
// ʹ��ǰ���������д�㷨��Ҫ��ǰ�������
iter_swap(iter1, iter2); // ���� iter1 �� iter2 ����ʾ��Ԫ�أ����� void
swap_ranges(beg1, end1, beg2); // �����뷶Χ������Ԫ���� beg2 ��ʼ�ĵڶ�������������Ԫ�ؽ��н�
�������ص�����ĵ� beg2��ָ�����һ������Ԫ��֮���λ�á�
replace(beg, end, old_val, new_val); // �� new_val �滻���� old_val ��ÿ��ƥ��Ԫ��
replace_if(beg, end, unaryPred, new_val); // �� new_val �滻���� unaryPred ��ÿ��ƥ��Ԫ��
// ʹ��˫���������д�㷨��Ҫ��˫��ѡ������ bidirectional iterator��
copy_backward(beg, end, dest); // �����뷶Χ�п���Ԫ�ص�ָ��Ŀ��λ�á������ΧΪ��,�򷵻�ֵΪ
dest�����򣬷���ֵ��ʾ�� *beg �п������ƶ���Ԫ�ء�
move_backward(beg, end, dest); //�����뷶Χ���ƶ�Ԫ�ص�ָ��Ŀ��λ�á������ΧΪ��,�򷵻�ֵΪ
dest������,����ֵ��ʾ�� *beg �п������ƶ���Ԫ�ء�
inplace_merge(beg, mid, end); // ��ͬһ�������е��������������кϲ�Ϊ��һ���������С� beg �� mid
��������к� mid �� end ��������б��ϲ�������д�뵽ԭ�����С�ʹ�� < �Ƚ�Ԫ�ء�
inplace_merge(beg, mid, end, comp); // ��ͬһ�������е��������������кϲ�Ϊ��һ���������С� beg
6 / 7
�� mid ��������к� mid �� end ��������б��ϲ�������д�뵽ԭ�����С�ʹ�ø����� comp ������
// �����㷨��Ҫ��˫��ѡ������ bidirectional iterator��
is_partitioned(beg, end, unaryPred); //�����������ν�� unaryPred ��Ԫ�ض��ڲ�����unarypred ��
Ԫ��֮ǰ���򷵻� true��������Ϊ�գ�Ҳ���� true
partition_copy(beg, end, dest1, dest2, unaryPred); // ������ unaryPred ��Ԫ�ؿ������� dest1��
���������� unaryPred ��Ԫ�ؿ������� dest2������һ�������� pair���� first ��Ա��ʾ������ dest1 �ĵ�Ԫ��
��ĩβ�� second ��ʾ������ dest2 ��Ԫ�ص�ĩβ��
partitioned_point(beg, end, unaryPred); // �������б������Ѿ��� unaryPred ���ֹ��ġ���������
unaryPred �ķ�Χ��β���������������صĵ��������� end������ָ���Ԫ�ؼ�����Ԫ�ر��붼������
unaryPred
stable_partition(beg, end, unaryPred); // ʹ�� unaryPred �����������С����� unaryPred ��Ԫ�ط�
�������п�ʼ���������Ԫ�ط�������β���� ���ص������� ָ�����һ������ unaryPred ��Ԫ��֮���λ�������
��Ԫ�ض������� unaryPred���򷵻� beg
partition(beg, end, unaryPred); // ʹ�� unaryPred �����������С����� unaryPred ��Ԫ�ط���������
��ʼ���������Ԫ�ط�������β���� ���ص������� ָ�����һ������ unaryPred ��Ԫ��֮���λ���������Ԫ�ض�
������ unaryPred���򷵻� beg
// �����㷨��Ҫ��������ʵ������� random-access iterator��
sort(beg, end); // ����������Χ
stable_sort(beg, end); // ����������Χ���ȶ�����
sort(beg, end, comp); // ����������Χ
stable_sort(beg, end, comp); // ����������Χ���ȶ�����
is_sorted(beg, end); // ����һ�� bool ֵ��ָ���������������Ƿ�����
is_sorted(beg, end, comp); // ����һ�� bool ֵ��ָ���������������Ƿ�����
is_sorted_until(beg, end); // �����������Ж������ʼ���������У������������е�β�������
is_sorted_until(beg, end, comp); // �����������Ж������ʼ���������У������������е�β�����
��
partial_sort(beg, mid, end); // ���� mid-beg ��Ԫ�ء�������� mid-beg ���� 42����˺�����ֵ��С
�� 42 ��Ԫ�������������ǰ 42 ��λ��
partial_sort(beg, mid, end, comp); // ���� mid-beg ��Ԫ�ء�������� mid-beg ���� 42����˺���
��ֵ��С�� 42 ��Ԫ�������������ǰ 42 ��λ��
partial_sort_copy(beg, end, destBeg, destEnd); // �������뷶Χ�е�Ԫ�أ������㹻���������Ԫ
�طŵ� destBeg �� destEnd ��ָʾ��������
partial_sort_copy(beg, end, destBeg, destEnd, comp); // �������뷶Χ�е�Ԫ�أ������㹻���
������Ԫ�طŵ� destBeg �� destEnd ��ָʾ��������
nth_element(beg, nth, end); // nth ��һ����������ָ�����������е� n ���Ԫ�ء� nth ֮ǰ��Ԫ�ض�С
�ڵ���������֮���Ԫ�ض����ڵ�����
nth_element(beg, nth, end, comp); // nth ��һ����������ָ�����������е� n ���Ԫ�ء� nth ֮ǰ��
Ԫ�ض�С�ڵ���������֮���Ԫ�ض����ڵ�����
// ʹ��ǰ��������������㷨����ͨ�汾���������������ڲ�����Ԫ�أ� _copy �汾������ĺ�д�뵽ָ��Ŀ����
���У������ı���������
remove(beg, end, val); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ�� ==val ��Ԫ�أ�����һ��ָ�����
һ��ɾ��Ԫ�ص�β��λ�õĵ�����
remove_if(beg, end, unaryPred);//ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ������ unaryPred ��Ԫ�أ�
����һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
remove_copy(beg, end, dest, val); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ�� ==val ��Ԫ�أ���
��һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
remove_copy_if(beg, end, dest, unaryPred); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ������
unaryPred ��Ԫ�أ�����һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
unique(beg, end); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� == ȷ���Ƿ���ͬ��ʵ���������С� ���ص������� ָ��
���ظ�Ԫ�ص�β��λ��
7 / 7
unique (beg, end, binaryPred); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� binaryPred ȷ���Ƿ���ͬ��ʵ����
�����С� ���ص������� ָ���ظ�Ԫ�ص�β��λ��
unique_copy(beg, end, dest); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� == ȷ���Ƿ���ͬ��ʵ���������С� ����
�������� ָ���ظ�Ԫ�ص�β��λ��
unique_copy_if(beg, end, dest, binaryPred); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� binaryPred ȷ����
����ͬ�� ʵ���������С� ���ص������� ָ���ظ�Ԫ�ص�β��λ��
rotate(beg, mid, end); // Χ�� mid ָ���Ԫ�ؽ���Ԫ��ת����Ԫ�� mid ��ΪΪ��Ԫ�أ������ mid+1 ��
�� end ֮ǰ��Ԫ�أ��ٽ����� beg �� mid ֮ǰ��Ԫ�ء� ���ص������� ָ��ԭ���� beg λ�õ�Ԫ��
rotate_copy(beg, mid, end, dest); // Χ�� mid ָ���Ԫ�ؽ���Ԫ��ת����Ԫ�� mid ��ΪΪ��Ԫ�أ���
���� mid+1 ���� end ֮ǰ��Ԫ�أ��ٽ����� beg �� mid ֮ǰ��Ԫ�ء� ���ص������� ָ��ԭ���� beg λ�õ�Ԫ��
// ʹ��˫��������������㷨
reverse(beg, end); // ��ת�����е�Ԫ�أ����� void
reverse_copy(beg, end, dest);; // ��ת�����е�Ԫ�أ� ���ص������� ָ�򿽱���Ŀ�����е�Ԫ�ص�β��
λ��
// ʹ��������ʵ������������㷨
random_shuffle(beg, end); // ��ϴ���������е�Ԫ�أ����� void
random_shuffle(beg, end, rand); // ��ϴ���������е�Ԫ�أ� rand ����һ����������������󣬷���
void
shuffle(beg, end, Uniform_rand); // ��ϴ���������е�Ԫ�أ� Uniform_rand ����������ȷֲ��������
������Ҫ�󣬷��� void
// ��Сֵ�����ֵ��ʹ�� < �����������ıȽϲ��� comp ���бȽ�
min(val1, va12); // ���� val1 �� val2 �е���Сֵ������ʵ�ε����ͱ�����ȫһ�¡������ͷ������Ͷ���
const �������ã���ζ�Ŷ��󲻻ᱻ����������
min(val1, val2, comp);
min(init_list);
min(init_list, comp);
max(val1, val2);
max(val1, val2, comp);
max(init_list);
max(init_list, comp);
minmax(val1, val2); // ����һ�� pair���� first ��ԱΪ�ṩ��ֵ�еĽ�С�ߣ� second ��ԱΪ�ϴ��ߡ�����
minmax(vall, val2, comp);
minmax(init_list);
minmax(init_list, comp);
min_element(beg, end); // ����ָ��������������СԪ�صĵ�����
min_element(beg, end, comp); // ����ָ��������������СԪ�صĵ�����
max_element(beg, end); // ����ָ���������������Ԫ�صĵ�����
max_element(beg, end, comp); // ����ָ���������������Ԫ�صĵ�����
minmax_element(beg, end); // ����һ�� pair������ first ��ԱΪ��СԪ�أ� second ��ԱΪ���Ԫ��
minmax_element(beg, end, comp); // ����һ�� pair������ first ��ԱΪ��СԪ�أ� second ��ԱΪ���
Ԫ��
// �ֵ���Ƚϣ����ݵ�һ�Բ���ȵ�Ԫ�ص���Դ�С�����ؽ���������һ���������ֵ�����С�ڵڶ������У���
���� true�����򣬷��� fa1se����������б���һ���̣�������Ԫ�ض���ϳ����еĶ�ӦԪ����ȣ���϶�������
�ֵ����и�С��������г�����ȣ��Ҷ�ӦԪ�ض���ȣ������ֵ������κ�һ��������������һ����
lexicographical_compare(beg1, end1, beg2, end2);
lexicographical_compare(beg1, end1, beg2, end2, comp);

*/