<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn"%>
<%@ taglib uri="http://www.springframework.org/tags" prefix="spring" %>
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<c:set var="cp" value="<%=request.getContextPath() %>"/>
<c:set var="rp" value='<%=request.getAttribute("javax.servlet.forward.request_uri")%>'/>
<!DOCTYPE html>
<html>
<head>
<title>Bank</title>
<link rel="stylesheet" type="text/css" href="${cp }/resources/style.css">
<link rel="stylesheet" type="text/css" href="${cp }/resources/bank.css">
<script>
var contextPath = '<c:out value="${cp}"/>';
var realPath = '<c:out value="${rp}"/>';
if (typeof bank == 'undefined') {
	bank = {};
}
</script>
</head>
<body>
<!-- Sql 질의문 2개를 이용하여 해당 정보 조회 -->
<section class="bank">
<c:forEach items="${branches }" var="branch">
	<article>
		<header>
			<h6>
				<c:out value="${branch.branchName}"/>
			</h6>
		</header>
		<table>
			<thead>
				<tr>
					<th>고객명</th>
					<th>예금총액</th>
				</tr>
			</thead>
			<tbody>
				<c:choose>
					<c:when test="${fn:length(clientMap[branch.branchName]) ne 0 }">
						<c:forEach items="${clientMap[branch.branchName] }" var="client" >
						<tr>
							<td><c:out value="${client.name }"/></td>
							<td><c:out value="${client.deposit.balance }"/></td>
						</tr>
						</c:forEach>
					</c:when>
					<c:otherwise>
						<tr>
							<td colspan="2">데이터가 존재하지 않습니다.</td>
						</tr>
					</c:otherwise>
				</c:choose>
			</tbody>
		</table>
	</article>	
</c:forEach>
</section>

<!-- 여러번 질의를 날려 정보를 조회 -->
<section class="bank">
<c:forEach items="${branches2 }" var="branch">
	<article>
		<header>
			<h6>
				<c:out value="${branch.branchName}"/>
			</h6>
		</header>
		<table>
			<thead>
				<tr>
					<th>고객명</th>
					<th>예금총액</th>
				</tr>
			</thead>
			<tbody>
				<c:choose>
					<c:when test="${fn:length(clientMap2[branch.branchName]) ne 0 }">
						<c:forEach items="${clientMap2[branch.branchName] }" var="client" >
						<tr>
							<td><c:out value="${client.name }"/></td>
							<td><c:out value="${client.deposit.balance }"/></td>
						</tr>
						</c:forEach>
					</c:when>
					<c:otherwise>
						<tr>
							<td colspan="2">데이터가 존재하지 않습니다.</td>
						</tr>
					</c:otherwise>
				</c:choose>
			</tbody>
		</table>
	</article>	
</c:forEach>
</section>

</body>
</html>