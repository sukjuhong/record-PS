-- 코드를 입력하세요
SELECT FLAVOR
FROM JULY J JOIN FIRST_HALF F USING (FLAVOR)
GROUP BY FLAVOR
ORDER BY SUM(J.TOTAL_ORDER + F.TOTAL_ORDER) DESC
LIMIT 3;