from django.conf.urls import url
from . import views
urlpatterns=[
    url(r'^$',views.product_list,name='product_list'),
    url(r'^product/(?P<pk>\d+)/$',views.product_details,name='product_details'),
    url(r'^product/new/$',views.product_new,name='product_new'),
]
