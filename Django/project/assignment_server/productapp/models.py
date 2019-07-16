from django.db import models

# Create your models here.
class Product(models.Model):
    name=models.CharField(max_length=200)
    brand_id=models.ForeignKey('Brand', on_delete=models.CASCADE, )

    def publish(self):
        self.save()

    def __str__(self):
        return self.name

class Brand(models.Model):
    name2=models.CharField(max_length=200)

    def publish(self):
        self.save()

    def __str__(self):
        return self.name2
