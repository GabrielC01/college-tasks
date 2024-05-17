# Subprograma principal.
function main()
	# Matriz de adjacência.
	ma_grafo::Matrix{Int} = [
		0 7 3 0 0 1 0;
		7 0 0 1 0 5 0; 
		3 0 0 0 3 7 0; 
		0 1 0 0 0 1 1; 
		0 0 3 0 0 7 3; 
		1 5 7 1 7 0 0; 
		0 0 0 1 3 0 0
	]

	@time vec_dist = bellmanford(ma_grafo, 1)
	println(vec_dist)

	@time vec_dist = dijkstra(ma_grafo, 1)
	println(vec_dist)
end


# Técnica de Bellman-Ford.
function bellmanford(ma_adj::Matrix{Int}, nodo_orig::Int)
	nodos_num = size(ma_adj, 2)
	# Inicializa o vetor de distâncias.
	vec_dist::Array{Int, 1} = fill(typemax(Int), nodos_num)
	vec_dist[nodo_orig] = 0

	# Relaxamento.
	count = 0
	for i in 1:nodos_num - 1
		# "Para cada aresta (u, v)..."
		for u in 1:nodos_num
			for v in 1:nodos_num
				if ma_adj[u, v] != 0 && vec_dist[v] > vec_dist[u] + ma_adj[u, v]
					vec_dist[v] = vec_dist[u] + ma_adj[u, v]
				end
			end
		end
	end

	# Saída.
	return vec_dist
end


# Técnica de Dijkstra.
function dijkstra(ma_adj::Matrix{Int}, nodo_orig::Int)
	nodos_num = size(ma_adj, 2)
	# Inicializa o vetor de distâncias.
	vec_dist::Array{Int, 1} = fill(typemax(Int), nodos_num)
	vec_dist[nodo_orig] = 0
	visitados = Set()

	# Relaxamento.
	while length(visitados) < nodos_num
		# Seleciona o menor nodo não visitado.
		nao_visitados = Set()
		for (i, v) in enumerate(vec_dist)
			if !(i in visitados)
				push!(nao_visitados, (i, v))
			end
		end
		nodo_menor = minimum(nao_visitados)[1]
		push!(visitados, nodo_menor)

		for v in 1:nodos_num
			if ma_adj[nodo_menor, v] != 0
				if vec_dist[v] > vec_dist[nodo_menor] + ma_adj[nodo_menor, v]
					vec_dist[v] = vec_dist[nodo_menor] + ma_adj[nodo_menor, v]
				end
			end
		end
	end

	return vec_dist
end

main()
