
<!-- README.md is generated from README.Rmd. Please edit that file -->

# GREED : Bayesian greedy clustering

<!-- badges: start -->

[![R build
status](https://github.com/comeetie/greed/workflows/R-CMD-check/badge.svg)](https://github.com/comeetie/greed/actions)
[![CRAN
status](https://www.r-pkg.org/badges/version/greed)](https://CRAN.R-project.org/package=greed)
<!-- badges: end -->

Greed enables model-based clustering of networks, matrices of count data
and much more with different types of generative models. Model-selection
and clustering are performed in combination by optimizing the Integrated
Classification Likelihood. Details of the algorithms and methods
proposed by this package can be found in Côme, Jouvin, Latouche, and
Bouveyron (2021)
[10.1007/s11634-021-00440-z](https://doi.org/10.1007/s11634-021-00440-z).

<img src="man/figures/greed.png" width=200 align="right" />

Dedicated to clustering and visualization, the package is very general
and currently handles the following tasks:

-   **Continuous data clustering** with Gaussian Mixture Models. A
    tutorial is available in `vignette("GMM")`. See also the
    documentation for the `Gmm` and `DiagGmm` S4 classes.
-   **Graph data clustering** with the Stochastic Block Model or its
    degree corrected variants. A tutorial is available in
    `vignette("SBM")`. See also the documentation for the `Sbm` and
    `dcSbm` S4 classes.
-   **Categorical data clustering** with the Latent Class Analysis. A
    tutorial is available in `vignette("LCA")`. See also the
    documentation for the `Lca` S4 class.
-   **Count data clustering** with the Mixture of Multinomials model. A
    tutorial will soon be available in `vignette("MoM")`. For now, we
    refer to the documentation for the `Mom` S4 class.
-   **Mixed-typed** data clustering, *e.g.* categorical and numerical
    but the package handles virtually any type of data combination by
    stacking models on top of each data types. For example graph data
    with continuous or categorical data attached to the nodes are
    handled. A tutorial is available in `vignette("Mixed-Models")`. See
    also the documentation for the `MixedModels` S4 class.
-   **Mixture of regression** for simultaneous clustering and fitting a
    regression model in each cluster. A tutorial is available in
    `vignette("MoR")`. See also the documentation for the `MoR` S4
    class.
-   **Co-clustering** of binary and count-data via the Latent Block
    Model and its degree-corrected variant. A tutorial will soon be
    available in `vignette("LBM")`. For now, we refer to the
    documentation for the `DcLbm` S4 class.

<!-- The following generative models are currently available:  -->
<!-- * **Stochastic Block Models** (see ``?`Sbm-class` ``), -->
<!-- * **Degree Corrected Stochastic Block Models** (see ``?`DcSbm-class` ``), -->
<!-- * **Multinomial Stochastic Block Models** (see ``?`MultSbm-class` ``), -->
<!-- * **Mixture of Multinomials** (see ``?`MoR-class` ``),  -->
<!-- * **Latent Class Analysis** (see ``?`Lca-class` ``),  -->
<!-- * **Gaussian Mixture Model** (see ``?`Gmm-class` `` and ``?`DiagGmm-class` ``), -->
<!-- * **Multivariate Mixture of Gaussian Regression Model** (see ``?`MoR-class` ``), -->
<!-- * **Degree Corrected Latent Block Model** (see ``?`DcLbm-class` ``). -->
<!-- * **Mixed Dlvm's** (see ``?`MixedModels-class` ``). -->

With the Integrated Classification Likelihood, the parameters of the
models are integrated out with a natural regularization effect for
complex models. This penalization allows to automatically find a
suitable value for the number of clusters *K*<sup>⋆</sup>. A user only
needs to provide an initial guess for the number of clusters *K*, as
well as values for the prior parameters (reasonable default values are
used if no prior information is given). The default optimization is
performed thanks to a combination of a greedy local search and a genetic
algorithm described in [Côme, Jouvin, Latouche, and Bouveyron
(2021)](https://doi.org/10.1007/s11634-021-00440-z), but several other
optimization algorithms are also available.

Eventually, a whole hierarchy of solutions from *K*<sup>⋆</sup> to 1
cluster is extracted. This enables an ordering of the clusters, and the
exploration of simpler clustering along the hierarchy. The package also
provides some plotting functionality.

## Installation

You can install the development version of greed from
[GitHub](https://github.com/) with:

``` r
#GitHub
install.packages("devtools")
devtools::install_github("comeetie/greed")
```

Or use the CRAN version:

``` r
#CRAN
install.packages("greed")
```

## Usage: the greed function

The main entry point for using the package is simply the`greed` function
(see `?greed`). The generative model will be chosen automatically to fit
the type of the provided data, but you may specify another choice with
the `model` argument.

We illustrate its use on a **graph clustering** example with the
classical Books network `?Books`.

> More use cases and their specific plotting functionality are described
> in the vignettes.

``` r
library(greed)
data(Books)
sol <- greed(Books$X) 
#> 
#> ── Fitting a guess DCSBM model ──
#> 
#> ℹ Initializing a population of 20 solutions.
#> ℹ Generation 1 : best solution with an ICL of -1346 and 4 clusters.
#> ℹ Generation 2 : best solution with an ICL of -1346 and 4 clusters.
#> ── Final clustering ──
#> 
#> ── Clustering with a DCSBM model 3 clusters and an ICL of -1345
```

You may specify the model you want to use and set the priors parameters
with the (`model` argument), the optimization algorithm (`alg` argument)
and the initial number of cluster `K`. Here `Books$X` is a square sparse
matrix and a graph clustering `` ?`DcSbm-class` `` model will be used by
default. By default, the Hybrid genetic algorithm is used.

The next example illustrates a usage without default values. A binary
`Sbm` prior is used, along with a spectral clustering algorithm for
graphs.

``` r
sol <- greed(Books$X,model=Sbm(),alg=Seed(),K=10)
#> 
#> ── Fitting a guess SBM model ──
#> 
#> ── Final clustering ──
#> 
#> ── Clustering with a SBM model 5 clusters and an ICL of -1316
```

## Result analysis

The results of `greed()` is an S4 class which depends on the `model`
argument (here, an SBM) which comes with readily implemented methods:
`clustering()` to access the estimated partitions, `K()` the estimated
number of clusters, and `coef()` the (conditional) maximum a posteriori
of the model parameters.

``` r
table(Books$label,clustering(sol)) %>% knitr::kable()
```

|     |   1 |   2 |   3 |   4 |   5 |
|:----|----:|----:|----:|----:|----:|
| c   |  30 |  16 |   2 |   1 |   0 |
| l   |   0 |   0 |   5 |  25 |  13 |
| n   |   0 |   7 |   4 |   2 |   0 |

``` r
K(sol)
#> [1] 5
coef(sol)
#> $pi
#> [1] 0.2857143 0.2190476 0.1047619 0.2666667 0.1238095
#> 
#> $thetakl
#>             [,1]       [,2]        [,3]        [,4]       [,5]
#> [1,] 0.310344828 0.06521739 0.009090909 0.000000000 0.00000000
#> [2,] 0.065217391 0.13043478 0.019762846 0.010869565 0.01337793
#> [3,] 0.009090909 0.01976285 0.436363636 0.006493506 0.04895105
#> [4,] 0.000000000 0.01086957 0.006493506 0.084656085 0.27747253
#> [5,] 0.000000000 0.01337793 0.048951049 0.277472527 0.55128205
```

## Inspecting the hierarchy

An important aspect of the **greed** package is its hierarchical
clustering algorithm which extract a set of nested partitions from
`K=K(sol)` to `K=1`. This hierarchy may be visualized thanks to a
dendogram representing the fusion order and the level of regularization
 − log (*α*) needed for each fusion.

``` r
plot(sol, type='tree') # try also: type="path"
```

<img src="man/figures/unnamed-chunk-2-1.png" width="90%" />

Moreover, similar to standard hierarchical algorithm such as `hclust`,
the `cut()` method allows you to extract a partition at any stage of the
hierarchy. Its results is still an S4 object, and the S4 methods
introduced earlier may again be used to investigate the results.

``` r
sol_K3 = cut(sol, K=3)
K(sol_K3)
#> [1] 3
table(Books$label,clustering(sol_K3)) %>% knitr::kable()
```

|     |   1 |   2 |   3 |
|:----|----:|----:|----:|
| c   |  30 |  18 |   1 |
| l   |   0 |   5 |  38 |
| n   |   0 |  11 |   2 |

## Visualization

Finally, the **greed** package propose efficient and model-adapted
visualization via the `plot()` methods. In this graph clustering
example, the `"blocks"` and `"nodelink"` display the cluster-aggregated
adjacency matrix and diagram of the graph respectively. Note that the
ordering of the clusters is the same than the one computed for the
dendrogram, greatly enhancing visualization of the hierarchical
structure.

``` r
plot(sol,type='blocks')
plot(sol, type='nodelink')
```

<img src="man/figures/plot-1.png" width="90%" /><img src="man/figures/plot-2.png" width="90%" />

## Other models

As explained above, the greed package implements many standard models
and the list may be displayed with

``` r
available_models()
```

Many plotting functions are available and, depending of the specified
`model`, different `type` argument may be specified. For further
information we refer to the vignettes linked above for each use case.

<!-- > See the `vignette("GMM")` for an in-depth tutorial. -->
<!-- > See the `vignette("LCA")` for details. -->
<!-- > See the `vignette("SBM")` for details. -->
<!-- > See the `vignette("MoR")` for details. -->
<!-- > See the `vignette("Mixed-Models")`for details. -->

## Using parallel computing

For large datasets, it is possible to use parallelism to speed-up the
computations thanks to the
[future](https://github.com/HenrikBengtsson/future) package. You only
need to specify the type of back-end you want to use, before calling the
`?greed` function:

``` r
library(future)
plan(multisession, workers=2) # may be increased
```
