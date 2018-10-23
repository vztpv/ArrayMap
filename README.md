# ArrayMap
ArrayMap : std::vector + Red-Black Tree
# Characteristic
  1. When inserting many(>100000) sorted data in sequence (at first), the speed is faster than std :: map. 
  2. When you call the insert function, the value is not stored in the tree. We postpone as much as possible. 
  3. Add it when you really need to add it to the tree, sort the collected data using std :: sort and add it to the tree. 
  4. It is best to just use the insert several times at a time.
  5. Since it is based on vector, it takes less time to delete than std :: map.
# Features and Cautions
  1. insert (lazy-insert) 
  2. update (It is better to postpone the postponed insertion and postpone as much as possible) 
  3. remove (remove item, O (log (n)), recycle using flag without shifting when removing, more testing required) 
  4. Note that there are iterators, but they do not traverse in the sorted order! 
  5. It seems that you should use parallel sort to get good performance.
  
# 특징
  1. 정렬된 데이터(>100000)를 차례대로 삽입하는 경우 속도가 std::map보다 빠르다.
  2. insert함수를 호출했을 때 바로 트리에 값이 저장되지 않는다. 최대한으로 미룬다. 
  3. 실제로 트리에 추가해야 할 떄 추가하며, std::sort를 이용해 모아 놓은 데이터들을 정렬한 후 트리에 추가한다.
  4. 한번에 insert를 여러 번 하고 나서 사용하기만 하는것이 가장 좋다. (만들 떄 가정한 상황이다)
  5. vector기반이므로 std::map보다 삭제했을떄 걸리는 시간이 짧다.
# 기능 및 주의사항
  1. insert (lazy-insert)
  2. update (미뤄둔 삽입을 진행, 최대한 미루는 것이 좋다)
  3. remove (항목제거, O(log(n)), 제거시 shift를 하지 않고 flag를 이용하여 재활용을 함, 테스트가 더 필요함)
  4. iterator가 있으나, 순회를 할 떄 소팅된 순서로 순회하지 않음에 주의해야한다! 
  5. quick sort가 병렬을 이용해야 성능이 좋게 나오는것 같다.
