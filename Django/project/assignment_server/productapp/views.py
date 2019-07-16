from django.shortcuts import render, get_object_or_404
from productapp.models import Product
from .forms import ProductForm

def product_list(val):
    prods=Product.objects.all()
    return render(val, 'productapp/product_list.html',{'apple':prods})


def product_details(val, pk):
    prod = get_object_or_404(Product, pk=pk)
    return render(val, 'productapp/product_details.html', {'product':prod})


def product_new(request):
    if request.method == "POST":
        form = ProductForm(request.POST)
        if form.is_valid():
            product = form.save(commit=False)
            product.author = request.user
            product.save()
            return render(request, 'productapp/product_details.html', {'product': product})
    else:
        form = ProductForm()
        return render(request, 'productapp/product_edit.html', {'form': form})
